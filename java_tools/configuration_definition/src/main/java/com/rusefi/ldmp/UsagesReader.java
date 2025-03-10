package com.rusefi.ldmp;

import com.devexperts.logging.Logging;
import com.rusefi.EnumToString;
import com.rusefi.InvokeReader;
import com.rusefi.ReaderState;
import com.rusefi.output.*;
import org.yaml.snakeyaml.Yaml;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.Map;

public class UsagesReader {
    private final static Logging log = Logging.getLogging(UsagesReader.class);

    private final static String header = "// generated by gen_live_documentation.sh / UsagesReader.java\n";

    private final StringBuilder enumContent = new StringBuilder(header +
            "#pragma once\n" +
            "\n" +
            "typedef enum {\n");

    private final StringBuilder totalSensors = new StringBuilder();

    private final StringBuilder fancyNewStuff = new StringBuilder();

    private final StringBuilder fancyNewMenu = new StringBuilder();

    private final StringBuilder fragmentsContent = new StringBuilder(header);

    private final String extraPrepend = System.getProperty("UsagesReader.extra_prepend");

    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.err.println("One parameter expected: name of live data yaml input file");
            System.exit(-1);
        }
        String yamlFileName = args[0];
        Yaml yaml = new Yaml();
        Map<String, Object> data = yaml.load(new FileReader(yamlFileName));

        UsagesReader usagesReader = new UsagesReader();

        int sensorTsPosition = usagesReader.handleYaml(data, null);
        usagesReader.writeFiles();

        log.info("TS_TOTAL_OUTPUT_SIZE=" + sensorTsPosition);
        try (FileWriter fw = new FileWriter("console/binary/generated/total_live_data_generated.h")) {
            fw.write(header);
            fw.write("#define TS_TOTAL_OUTPUT_SIZE " + sensorTsPosition);
        }

        try (FileWriter fw = new FileWriter("console/binary/generated/sensors.java")) {
            fw.write(usagesReader.totalSensors.toString());
        }

        try (FileWriter fw = new FileWriter("console/binary/generated/fancy_content.ini")) {
            fw.write(usagesReader.fancyNewStuff.toString());
        }

        try (FileWriter fw = new FileWriter("console/binary/generated/fancy_menu.ini")) {
            fw.write(usagesReader.fancyNewMenu.toString());
        }
    }

    interface EntryHandler {
        void onEntry(String name, String javaName, String folder, String prepend, boolean withCDefines, String[] outputNames) throws IOException;
    }

    private int handleYaml(Map<String, Object> data, EntryHandler _handler) throws IOException {
        JavaSensorsConsumer javaSensorsConsumer = new JavaSensorsConsumer();
        String tsOutputsDestination = "console/binary/";

        ConfigurationConsumer outputsSections = new OutputsSectionConsumer(tsOutputsDestination + File.separator + "generated/output_channels.ini");

        ConfigurationConsumer dataLogConsumer = new DataLogConsumer(tsOutputsDestination + File.separator + "generated/data_logs.ini");

        EntryHandler handler = new EntryHandler() {
            @Override
            public void onEntry(String name, String javaName, String folder, String prepend, boolean withCDefines, String[] outputNames) throws IOException {
                // TODO: use outputNames

                int startingPosition = javaSensorsConsumer.sensorTsPosition;
                log.info("Starting " + name + " at " + startingPosition);

                ReaderState state = new ReaderState();
                state.setDefinitionInputFile(folder + File.separator + name + ".txt");
                state.withC_Defines = withCDefines;

                state.addDestination(javaSensorsConsumer,
                        outputsSections,
                        dataLogConsumer
                );
                FragmentDialogConsumer fragmentDialogConsumer = new FragmentDialogConsumer(name);
                state.addDestination(fragmentDialogConsumer);

                if (extraPrepend != null)
                    state.addPrepend(extraPrepend);
                state.addPrepend(prepend);
                state.addCHeaderDestination(folder + File.separator + name + "_generated.h");
                state.addJavaDestination("../java_console/models/src/main/java/com/rusefi/config/generated/" + javaName);
                state.doJob();

                fancyNewStuff.append(fragmentDialogConsumer.getContent());

                fancyNewMenu.append(fragmentDialogConsumer.menuLine());

                log.info("Done with " + name + " at " + javaSensorsConsumer.sensorTsPosition);
            }
        };

        ArrayList<LinkedHashMap> liveDocs = (ArrayList<LinkedHashMap>)data.get("Usages");

        for (LinkedHashMap entry : liveDocs) {
            String name = (String)entry.get("name");
            String java = (String)entry.get("java");
            String folder = (String)entry.get("folder");
            String prepend = (String)entry.get("prepend");
            Boolean withCDefines = (Boolean)entry.get("withCDefines");
            // Defaults to false if not specified
            withCDefines = withCDefines != null && withCDefines;

            Object outputNames = entry.get("output_name");

            String[] outputNamesArr;
            if (outputNames == null) {
                outputNamesArr = new String[0];
            } else if (outputNames instanceof String) {
                outputNamesArr = new String[1];
                outputNamesArr[0] = (String)outputNames;
            } else {
                ArrayList<String> nameList = (ArrayList<String>)outputNames;
                outputNamesArr = new String[nameList.size()];
                nameList.toArray(outputNamesArr);
            }

            handler.onEntry(name, java, folder, prepend, withCDefines, outputNamesArr);

            String enumName = "LDS_" + name;
            String type = name + "_s"; // convention
            enumContent.append(enumName + ",\n");

            if (outputNamesArr.length < 2) {
                fragmentsContent
                        .append("getLiveDataAddr<")
                        .append(type)
                        .append(">(),\n");
            } else {
                for (int i = 0; i < outputNamesArr.length; i++) {
                    if (i != 0) {
                        // TODO: remove once the rest of the handling for multiple copies of one struct is in place.
                        fragmentsContent.append("// ");
                    }

                    fragmentsContent
                            .append("getLiveDataAddr<")
                            .append(type)
                            .append(">(")
                            .append(i)
                            .append("),\t// ")
                            .append(outputNamesArr[i])
                            .append("\n");
                }
            }
        }
        enumContent.append("} live_data_e;\n");

        totalSensors.append(javaSensorsConsumer.getContent());

        return javaSensorsConsumer.sensorTsPosition;
    }

    private void writeFiles() throws IOException {
        String liveDataIdsHeader = "console/binary/generated/live_data_ids.h";
        try (FileWriter fw = new FileWriter(liveDataIdsHeader)) {
            fw.write(enumContent.toString());
        }

        try (FileWriter fw = new FileWriter("console/binary/generated/live_data_fragments.h")) {
            fw.write(fragmentsContent.toString());
        }

        String outputPath = "../java_console/io/src/main/java/com/rusefi/enums";
        InvokeReader request = new InvokeReader(outputPath, Collections.singletonList(liveDataIdsHeader));
        EnumToString.handleRequest(request);
    }
}
