#!/bin/bash

#
# it's totally possible to develop on Windows. Also WSL is amazing!
# TL,DR: use gcc 9.3
#
# by the way to uninstall package with old compiler version you might use
# sudo apt remove binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi
#

# This script will download and install all dependencies require to develop rusEFI on Linux.
# After running this script, executing `make` in the firmware folder is expected to produce a functional firmware binary.

# Update package lists
sudo apt-get update

# install dependencies
sudo apt-get install -y build-essential gcc make openjdk-8-jdk-headless ant mtools zip xxd

# delete any old tools, create a new folder, and go there
rm -rf ~/.rusefi-tools
mkdir ~/.rusefi-tools
cd ~/.rusefi-tools

# in case not first execution
rm -rf arm-none-eabi-gcc.tar.bz2

# Download and extract GCC compiler
curl -L -o arm-none-eabi-gcc.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2
tar -xjvf arm-none-eabi-gcc.tar.bz2

# Delete downloaded image
rm arm-none-eabi-gcc.tar.bz2

# Add the compiler to your path
echo 'export PATH=$PATH:$HOME/.rusefi-tools/gcc-arm-none-eabi-10.3-2021.10/bin' >> ~/.profile

# Allow the current user to use serial ports
sudo usermod -a -G dialout $USER
