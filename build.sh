#!/bin/bash
PROJECT_DIR=`pwd`
echo $PROJECT_DIR
# build in home directory, in case the project directory is on an NTFS filesystem, where 
# cmake doesn't work properly due to missing support for file flags and/or links
mkdir -p ~/builds/cpprun/build
cd ~/builds/cpprun/build
cmake -DCMAKE_INSTALL_PREFIX=~/builds/cpprun $PROJECT_DIR
cp ~/builds/cpprun/build/compile_commands.json $PROJECT_DIR/
make -j8 install 
cd ~/builds/cpprun/bin
./tests

