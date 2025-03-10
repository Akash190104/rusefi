#include "global.h"
#include "engine_types.h"
// was generated automatically by rusEFI tool  from engine_types.h // by enum2string.jar tool on Thu Oct 06 02:04:24 UTC 2022
// see also gen_config_and_enums.bat



const char *getBench_mode_e(bench_mode_e value){
switch(value) {
case BENCH_AC_COMPRESSOR_RELAY:
  return "BENCH_AC_COMPRESSOR_RELAY";
case BENCH_CHECK_ENGINE_LIGHT:
  return "BENCH_CHECK_ENGINE_LIGHT";
case BENCH_FAN_RELAY:
  return "BENCH_FAN_RELAY";
case BENCH_FAN_RELAY_2:
  return "BENCH_FAN_RELAY_2";
case BENCH_FUEL_PUMP:
  return "BENCH_FUEL_PUMP";
case BENCH_GPPWM1_VALVE:
  return "BENCH_GPPWM1_VALVE";
case BENCH_GPPWM2_VALVE:
  return "BENCH_GPPWM2_VALVE";
case BENCH_GPPWM3_VALVE:
  return "BENCH_GPPWM3_VALVE";
case BENCH_GPPWM4_VALVE:
  return "BENCH_GPPWM4_VALVE";
case BENCH_HPFP_VALVE:
  return "BENCH_HPFP_VALVE";
case BENCH_IDLE_VALVE:
  return "BENCH_IDLE_VALVE";
case BENCH_MAIN_RELAY:
  return "BENCH_MAIN_RELAY";
case BENCH_SECOND_IDLE_VALVE:
  return "BENCH_SECOND_IDLE_VALVE";
case BENCH_STARTER_DISABLE_RELAY:
  return "BENCH_STARTER_DISABLE_RELAY";
case BENCH_STARTER_ENABLE_RELAY:
  return "BENCH_STARTER_ENABLE_RELAY";
  }
 return NULL;
}
const char *getDebug_mode_e(debug_mode_e value){
switch(value) {
case DBG_0:
  return "DBG_0";
case DBG_10:
  return "DBG_10";
case DBG_11:
  return "DBG_11";
case DBG_16:
  return "DBG_16";
case DBG_2:
  return "DBG_2";
case DBG_20:
  return "DBG_20";
case DBG_24:
  return "DBG_24";
case DBG_26:
  return "DBG_26";
case DBG_29:
  return "DBG_29";
case DBG_34:
  return "DBG_34";
case DBG_35:
  return "DBG_35";
case DBG_36:
  return "DBG_36";
case DBG_37:
  return "DBG_37";
case DBG_38:
  return "DBG_38";
case DBG_43:
  return "DBG_43";
case DBG_46:
  return "DBG_46";
case DBG_7:
  return "DBG_7";
case DBG_8:
  return "DBG_8";
case DBG_9:
  return "DBG_9";
case DBG_ANALOG_INPUTS:
  return "DBG_ANALOG_INPUTS";
case DBG_ANALOG_INPUTS2:
  return "DBG_ANALOG_INPUTS2";
case DBG_BENCH_TEST:
  return "DBG_BENCH_TEST";
case DBG_CJ125:
  return "DBG_CJ125";
case DBG_COMPOSITE_LOG:
  return "DBG_COMPOSITE_LOG";
case DBG_DWELL_METRIC:
  return "DBG_DWELL_METRIC";
case DBG_DYNO_VIEW:
  return "DBG_DYNO_VIEW";
case DBG_ELECTRONIC_THROTTLE_PID:
  return "DBG_ELECTRONIC_THROTTLE_PID";
case DBG_EL_ACCEL:
  return "DBG_EL_ACCEL";
case DBG_ETB_AUTOTUNE:
  return "DBG_ETB_AUTOTUNE";
case DBG_EXECUTOR:
  return "DBG_EXECUTOR";
case DBG_INSTANT_RPM:
  return "DBG_INSTANT_RPM";
case DBG_ION:
  return "DBG_ION";
case DBG_KNOCK:
  return "DBG_KNOCK";
case DBG_LOGIC_ANALYZER:
  return "DBG_LOGIC_ANALYZER";
case DBG_LUA:
  return "DBG_LUA";
case DBG_MAP:
  return "DBG_MAP";
case DBG_METRICS:
  return "DBG_METRICS";
case DBG_SD_CARD:
  return "DBG_SD_CARD";
case DBG_SOFT_SPARK_CUT:
  return "DBG_SOFT_SPARK_CUT";
case DBG_SR5_PROTOCOL:
  return "DBG_SR5_PROTOCOL";
case DBG_STEPPER_IDLE_CONTROL:
  return "DBG_STEPPER_IDLE_CONTROL";
case DBG_TCU:
  return "DBG_TCU";
case DBG_TLE8888:
  return "DBG_TLE8888";
case DBG_TPS_ACCEL:
  return "DBG_TPS_ACCEL";
case DBG_TRIGGER_COUNTERS:
  return "DBG_TRIGGER_COUNTERS";
case DBG_UNUSED12:
  return "DBG_UNUSED12";
case DBG_UNUSED41:
  return "DBG_UNUSED41";
case DBG_UNUSED_42:
  return "DBG_UNUSED_42";
case UNUSED23:
  return "UNUSED23";
  }
 return NULL;
}
const char *getEngine_type_e(engine_type_e value){
switch(value) {
case BMW_M73_M:
  return "BMW_M73_M";
case BMW_M73_MRE:
  return "BMW_M73_MRE";
case BMW_M73_MRE_SLAVE:
  return "BMW_M73_MRE_SLAVE";
case CAMARO_4:
  return "CAMARO_4";
case CITROEN_TU3JP:
  return "CITROEN_TU3JP";
case DEFAULT_FRANKENSO:
  return "DEFAULT_FRANKENSO";
case DODGE_NEON_1995:
  return "DODGE_NEON_1995";
case DODGE_NEON_2003_CRANK:
  return "DODGE_NEON_2003_CRANK";
case DODGE_RAM:
  return "DODGE_RAM";
case EEPROM_BENCH_ENGINE:
  return "EEPROM_BENCH_ENGINE";
case ETB_BENCH_ENGINE:
  return "ETB_BENCH_ENGINE";
case ET_UNUSED96:
  return "ET_UNUSED96";
case ET_UNUSED97:
  return "ET_UNUSED97";
case ET_UNUSED98:
  return "ET_UNUSED98";
case ET_UNUSED_17:
  return "ET_UNUSED_17";
case FORD_ASPIRE_1996:
  return "FORD_ASPIRE_1996";
case FORD_ESCORT_GT:
  return "FORD_ESCORT_GT";
case FORD_INLINE_6_1995:
  return "FORD_INLINE_6_1995";
case FRANKENSO_BMW_M73_F:
  return "FRANKENSO_BMW_M73_F";
case FRANKENSO_MAZDA_MIATA_2003:
  return "FRANKENSO_MAZDA_MIATA_2003";
case FRANKENSO_MAZDA_MIATA_NA8:
  return "FRANKENSO_MAZDA_MIATA_NA8";
case FRANKENSO_MIATA_NA6_MAP:
  return "FRANKENSO_MIATA_NA6_MAP";
case FRANKENSO_MIATA_NA6_VAF:
  return "FRANKENSO_MIATA_NA6_VAF";
case FRANKENSO_QA_ENGINE:
  return "FRANKENSO_QA_ENGINE";
case Force_4_bytes_size_engine_type:
  return "Force_4_bytes_size_engine_type";
case GY6_139QMB:
  return "GY6_139QMB";
case HELLEN72_ETB:
  return "HELLEN72_ETB";
case HELLEN_121_NISSAN_4_CYL:
  return "HELLEN_121_NISSAN_4_CYL";
case HELLEN_121_NISSAN_6_CYL:
  return "HELLEN_121_NISSAN_6_CYL";
case HELLEN_121_NISSAN_8_CYL:
  return "HELLEN_121_NISSAN_8_CYL";
case HELLEN_121_NISSAN_ALMERA_N16:
  return "HELLEN_121_NISSAN_ALMERA_N16";
case HELLEN_121_VAG_4_CYL:
  return "HELLEN_121_VAG_4_CYL";
case HELLEN_121_VAG_5_CYL:
  return "HELLEN_121_VAG_5_CYL";
case HELLEN_121_VAG_8_CYL:
  return "HELLEN_121_VAG_8_CYL";
case HELLEN_121_VAG_V6_CYL:
  return "HELLEN_121_VAG_V6_CYL";
case HELLEN_121_VAG_VR6_CYL:
  return "HELLEN_121_VAG_VR6_CYL";
case HELLEN_128_MERCEDES_4_CYL:
  return "HELLEN_128_MERCEDES_4_CYL";
case HELLEN_128_MERCEDES_6_CYL:
  return "HELLEN_128_MERCEDES_6_CYL";
case HELLEN_128_MERCEDES_8_CYL:
  return "HELLEN_128_MERCEDES_8_CYL";
case HELLEN_134_BMW:
  return "HELLEN_134_BMW";
case HELLEN_154_HYUNDAI_COUPE_BK1:
  return "HELLEN_154_HYUNDAI_COUPE_BK1";
case HELLEN_154_HYUNDAI_COUPE_BK2:
  return "HELLEN_154_HYUNDAI_COUPE_BK2";
case HELLEN_154_VAG:
  return "HELLEN_154_VAG";
case HELLEN_55_BMW:
  return "HELLEN_55_BMW";
case HELLEN_88_BMW:
  return "HELLEN_88_BMW";
case HELLEN_NA6:
  return "HELLEN_NA6";
case HELLEN_NA8_96:
  return "HELLEN_NA8_96";
case HELLEN_NA94:
  return "HELLEN_NA94";
case HELLEN_NB1:
  return "HELLEN_NB1";
case HELLEN_NB1_36:
  return "HELLEN_NB1_36";
case HELLEN_NB2:
  return "HELLEN_NB2";
case HELLEN_NB2_36:
  return "HELLEN_NB2_36";
case HONDA_600:
  return "HONDA_600";
case L9779_BENCH_ENGINE:
  return "L9779_BENCH_ENGINE";
case MAZDA_MIATA_2003_BOARD_TEST:
  return "MAZDA_MIATA_2003_BOARD_TEST";
case MAZDA_MIATA_2003_NA_RAIL:
  return "MAZDA_MIATA_2003_NA_RAIL";
case MIATA_1996:
  return "MIATA_1996";
case MIATA_PROTEUS_TCU:
  return "MIATA_PROTEUS_TCU";
case MINIMAL_PINS:
  return "MINIMAL_PINS";
case MITSU_4G93:
  return "MITSU_4G93";
case MRE_BOARD_NEW_TEST:
  return "MRE_BOARD_NEW_TEST";
case MRE_BODY_CONTROL:
  return "MRE_BODY_CONTROL";
case MRE_M111:
  return "MRE_M111";
case MRE_MIATA_94_MAP:
  return "MRE_MIATA_94_MAP";
case MRE_MIATA_NA6_MAP:
  return "MRE_MIATA_NA6_MAP";
case MRE_MIATA_NA6_VAF:
  return "MRE_MIATA_NA6_VAF";
case MRE_MIATA_NB2_ETB:
  return "MRE_MIATA_NB2_ETB";
case MRE_MIATA_NB2_MAF:
  return "MRE_MIATA_NB2_MAF";
case MRE_MIATA_NB2_MAP:
  return "MRE_MIATA_NB2_MAP";
case MRE_SECONDARY_CAN:
  return "MRE_SECONDARY_CAN";
case MRE_SUBARU_EJ18:
  return "MRE_SUBARU_EJ18";
case MRE_VW_B6:
  return "MRE_VW_B6";
case NISSAN_PRIMERA:
  return "NISSAN_PRIMERA";
case PROTEUS_ANALOG_PWM_TEST:
  return "PROTEUS_ANALOG_PWM_TEST";
case PROTEUS_BMW_M73:
  return "PROTEUS_BMW_M73";
case PROTEUS_E65_6H_MAN_IN_THE_MIDDLE:
  return "PROTEUS_E65_6H_MAN_IN_THE_MIDDLE";
case PROTEUS_HARLEY:
  return "PROTEUS_HARLEY";
case PROTEUS_HONDA_K:
  return "PROTEUS_HONDA_K";
case PROTEUS_HONDA_OBD2A:
  return "PROTEUS_HONDA_OBD2A";
case PROTEUS_LUA_DEMO:
  return "PROTEUS_LUA_DEMO";
case PROTEUS_MIATA_NB2:
  return "PROTEUS_MIATA_NB2";
case PROTEUS_N73:
  return "PROTEUS_N73";
case PROTEUS_QC_TEST_BOARD:
  return "PROTEUS_QC_TEST_BOARD";
case PROTEUS_VAG_80_18T:
  return "PROTEUS_VAG_80_18T";
case PROTEUS_VW_B6:
  return "PROTEUS_VW_B6";
case SACHS:
  return "SACHS";
case SUBARUEG33_DEFAULTS:
  return "SUBARUEG33_DEFAULTS";
case SUBARU_2003_WRX:
  return "SUBARU_2003_WRX";
case TEST_100:
  return "TEST_100";
case TEST_101:
  return "TEST_101";
case TEST_102:
  return "TEST_102";
case TEST_33816:
  return "TEST_33816";
case TEST_CRANK_ENGINE:
  return "TEST_CRANK_ENGINE";
case TEST_ENGINE:
  return "TEST_ENGINE";
case TEST_ENGINE_VVT:
  return "TEST_ENGINE_VVT";
case TEST_ISSUE_366_BOTH:
  return "TEST_ISSUE_366_BOTH";
case TEST_ISSUE_366_RISE:
  return "TEST_ISSUE_366_RISE";
case TEST_ROTARY:
  return "TEST_ROTARY";
case TLE8888_BENCH_ENGINE:
  return "TLE8888_BENCH_ENGINE";
case TOYOTA_2JZ_GTE_VVTi:
  return "TOYOTA_2JZ_GTE_VVTi";
case UNUSED_27:
  return "UNUSED_27";
case UNUSED_38:
  return "UNUSED_38";
case UNUSED_48:
  return "UNUSED_48";
case VW_ABA:
  return "VW_ABA";
  }
 return NULL;
}
const char *getTrigger_type_e(trigger_type_e value){
switch(value) {
case Force_4_bytes_size_trigger_type:
  return "Force_4_bytes_size_trigger_type";
case TT_12_TOOTH_CRANK:
  return "TT_12_TOOTH_CRANK";
case TT_1_16:
  return "TT_1_16";
case TT_2JZ_3_34:
  return "TT_2JZ_3_34";
case TT_36_2_1:
  return "TT_36_2_1";
case TT_36_2_1_1:
  return "TT_36_2_1_1";
case TT_36_2_2_2:
  return "TT_36_2_2_2";
case TT_3_1_CAM:
  return "TT_3_1_CAM";
case TT_60_2_VW:
  return "TT_60_2_VW";
case TT_CHRYSLER_NGC_36_2_2:
  return "TT_CHRYSLER_NGC_36_2_2";
case TT_DAIHATSU:
  return "TT_DAIHATSU";
case TT_DODGE_NEON_1995:
  return "TT_DODGE_NEON_1995";
case TT_DODGE_NEON_1995_ONLY_CRANK:
  return "TT_DODGE_NEON_1995_ONLY_CRANK";
case TT_DODGE_NEON_2003_CAM:
  return "TT_DODGE_NEON_2003_CAM";
case TT_DODGE_NEON_2003_CRANK:
  return "TT_DODGE_NEON_2003_CRANK";
case TT_DODGE_RAM:
  return "TT_DODGE_RAM";
case TT_DODGE_STRATUS:
  return "TT_DODGE_STRATUS";
case TT_FIAT_IAW_P8:
  return "TT_FIAT_IAW_P8";
case TT_FORD_ASPIRE:
  return "TT_FORD_ASPIRE";
case TT_FORD_ST170:
  return "TT_FORD_ST170";
case TT_FORD_TFI_PIP:
  return "TT_FORD_TFI_PIP";
case TT_GM_24x:
  return "TT_GM_24x";
case TT_GM_24x_2:
  return "TT_GM_24x_2";
case TT_GM_60_2_2_2:
  return "TT_GM_60_2_2_2";
case TT_GM_7X:
  return "TT_GM_7X";
case TT_HONDA_CBR_600:
  return "TT_HONDA_CBR_600";
case TT_HONDA_K_CAM_4_1:
  return "TT_HONDA_K_CAM_4_1";
case TT_HONDA_K_CRANK_12_1:
  return "TT_HONDA_K_CRANK_12_1";
case TT_JEEP_18_2_2_2:
  return "TT_JEEP_18_2_2_2";
case TT_JEEP_4_CYL:
  return "TT_JEEP_4_CYL";
case TT_KAWA_KX450F:
  return "TT_KAWA_KX450F";
case TT_MAZDA_DOHC_1_4:
  return "TT_MAZDA_DOHC_1_4";
case TT_MAZDA_MIATA_NA:
  return "TT_MAZDA_MIATA_NA";
case TT_MAZDA_MIATA_NB1:
  return "TT_MAZDA_MIATA_NB1";
case TT_MAZDA_MIATA_VVT_TEST:
  return "TT_MAZDA_MIATA_VVT_TEST";
case TT_MAZDA_SOHC_4:
  return "TT_MAZDA_SOHC_4";
case TT_MERCEDES_2_SEGMENT:
  return "TT_MERCEDES_2_SEGMENT";
case TT_MIATA_VVT:
  return "TT_MIATA_VVT";
case TT_MITSUBISHI:
  return "TT_MITSUBISHI";
case TT_NISSAN_MR18_CAM_VVT:
  return "TT_NISSAN_MR18_CAM_VVT";
case TT_NISSAN_MR18_CRANK:
  return "TT_NISSAN_MR18_CRANK";
case TT_NISSAN_QR25:
  return "TT_NISSAN_QR25";
case TT_NISSAN_SR20VE:
  return "TT_NISSAN_SR20VE";
case TT_NISSAN_VQ30:
  return "TT_NISSAN_VQ30";
case TT_NISSAN_VQ35:
  return "TT_NISSAN_VQ35";
case TT_ONE:
  return "TT_ONE";
case TT_ONE_PLUS_ONE:
  return "TT_ONE_PLUS_ONE";
case TT_RENIX_44_2_2:
  return "TT_RENIX_44_2_2";
case TT_RENIX_66_2_2_2:
  return "TT_RENIX_66_2_2_2";
case TT_ROVER_K:
  return "TT_ROVER_K";
case TT_SKODA_FAVORIT:
  return "TT_SKODA_FAVORIT";
case TT_SUBARU_7_6:
  return "TT_SUBARU_7_6";
case TT_SUBARU_7_WITHOUT_6:
  return "TT_SUBARU_7_WITHOUT_6";
case TT_SUBARU_EZ30:
  return "TT_SUBARU_EZ30";
case TT_SUBARU_SVX:
  return "TT_SUBARU_SVX";
case TT_SUBARU_SVX_CAM_VVT:
  return "TT_SUBARU_SVX_CAM_VVT";
case TT_SUBARU_SVX_CRANK_1:
  return "TT_SUBARU_SVX_CRANK_1";
case TT_SUZUKI_G13B:
  return "TT_SUZUKI_G13B";
case TT_TOOTHED_WHEEL:
  return "TT_TOOTHED_WHEEL";
case TT_TOOTHED_WHEEL_32_2:
  return "TT_TOOTHED_WHEEL_32_2";
case TT_TOOTHED_WHEEL_36_1:
  return "TT_TOOTHED_WHEEL_36_1";
case TT_TOOTHED_WHEEL_36_2:
  return "TT_TOOTHED_WHEEL_36_2";
case TT_TOOTHED_WHEEL_60_2:
  return "TT_TOOTHED_WHEEL_60_2";
case TT_TRI_TACH:
  return "TT_TRI_TACH";
case TT_UNUSED:
  return "TT_UNUSED";
case TT_VVT_BARRA_3_PLUS_1:
  return "TT_VVT_BARRA_3_PLUS_1";
case TT_VVT_BOSCH_QUICK_START:
  return "TT_VVT_BOSCH_QUICK_START";
case TT_VVT_JZ:
  return "TT_VVT_JZ";
case TT_VVT_MAZDA_SKYACTIV:
  return "TT_VVT_MAZDA_SKYACTIV";
case TT_VVT_MIATA_NB:
  return "TT_VVT_MIATA_NB";
case TT_VVT_MITSUBISHI_3A92:
  return "TT_VVT_MITSUBISHI_3A92";
case TT_VVT_MITSUBISHI_6G75:
  return "TT_VVT_MITSUBISHI_6G75";
case TT_VVT_NISSAN_VQ35:
  return "TT_VVT_NISSAN_VQ35";
case TT_VVT_TOYOTA_4_1:
  return "TT_VVT_TOYOTA_4_1";
case UNUSED_21:
  return "UNUSED_21";
case UNUSED_29:
  return "UNUSED_29";
case UNUSED_34:
  return "UNUSED_34";
  }
 return NULL;
}
const char *getTs_command_e(ts_command_e value){
switch(value) {
case TS_BENCH_CATEGORY:
  return "TS_BENCH_CATEGORY";
case TS_CLEAR_WARNINGS:
  return "TS_CLEAR_WARNINGS";
case TS_COMMAND_1:
  return "TS_COMMAND_1";
case TS_COMMAND_11:
  return "TS_COMMAND_11";
case TS_COMMAND_12:
  return "TS_COMMAND_12";
case TS_COMMAND_13:
  return "TS_COMMAND_13";
case TS_COMMAND_14:
  return "TS_COMMAND_14";
case TS_COMMAND_15:
  return "TS_COMMAND_15";
case TS_COMMAND_16:
  return "TS_COMMAND_16";
case TS_COMMAND_4:
  return "TS_COMMAND_4";
case TS_COMMAND_5:
  return "TS_COMMAND_5";
case TS_COMMAND_9:
  return "TS_COMMAND_9";
case TS_DEBUG_MODE:
  return "TS_DEBUG_MODE";
case TS_GRAB_PEDAL_UP:
  return "TS_GRAB_PEDAL_UP";
case TS_GRAB_PEDAL_WOT:
  return "TS_GRAB_PEDAL_WOT";
case TS_GRAB_TPS_CLOSED:
  return "TS_GRAB_TPS_CLOSED";
case TS_GRAB_TPS_WOT:
  return "TS_GRAB_TPS_WOT";
case TS_IGNITION_CATEGORY:
  return "TS_IGNITION_CATEGORY";
case TS_INJECTOR_CATEGORY:
  return "TS_INJECTOR_CATEGORY";
case TS_LUA_OUTPUT_CATEGORY:
  return "TS_LUA_OUTPUT_CATEGORY";
case TS_RESET_TLE8888:
  return "TS_RESET_TLE8888";
case TS_SET_DEFAULT_ENGINE:
  return "TS_SET_DEFAULT_ENGINE";
case TS_SET_ENGINE_TYPE:
  return "TS_SET_ENGINE_TYPE";
case TS_SOLENOID_CATEGORY:
  return "TS_SOLENOID_CATEGORY";
case TS_UNUSED_23:
  return "TS_UNUSED_23";
case TS_UNUSED_26:
  return "TS_UNUSED_26";
case TS_UNUSED_27:
  return "TS_UNUSED_27";
case TS_UNUSED_28:
  return "TS_UNUSED_28";
case TS_UNUSED_29:
  return "TS_UNUSED_29";
case TS_UNUSED_CJ125_CALIB:
  return "TS_UNUSED_CJ125_CALIB";
case TS_WIDEBAND:
  return "TS_WIDEBAND";
case TS_WRITE_FLASH:
  return "TS_WRITE_FLASH";
case TS_X14:
  return "TS_X14";
  }
 return NULL;
}
