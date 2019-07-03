#!/bin/bash
PROJECT_DIR=`pwd`
# build in home directory, in case the project directory is on an NTFS filesystem, where 
# cmake doesn't work properly due to missing support for file flags and/or links
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
(cd ..; ln -s build/compile_commands.json compile_commands.json)
make -j8 
./tests

