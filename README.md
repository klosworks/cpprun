# cpprun

This is a tool designed to run c++ programs as scripts.

# installation

Please, clone this repository and run

```
./build.sh
```

Then you can install on the system with:
```
sudo ./install.sh
```

If you don't want to modify your system, install in your home directory

First, prepare .local/bin directory:
```
mkdir ~/.local
mkdir ~/.local/bin
cat "export PATH=PATH:~/.local/bin" >> ~/.bashrc
source ~/.bashrc
```
then install:
```
CMAKE_INSTALL_PREFIX=~/.local/bin ./install.sh 
```

# usage 

```
cpprun script.cpp
```

The tool will compile the code into a temporary directory and run it from the directory it was run from.

The c++ code is normal C++ code, for example

```
#include <iostream>
int main(int argc, char** argv)
{
    std::cout << "Hello world!\n";
}
```

If you want to run the file directly like this:

```
./script.cpp
```

then add the following line at the beginning

```
///usr/bin/env cpprun ${0%%.cpp}
```

It uses CMake. You can put cmake commands at the beginning of the file in a comment, in order to pull dependencies.

https://gist.github.com/jdarpinian/1952a58b823222627cc1a8b83a7aa4e2
