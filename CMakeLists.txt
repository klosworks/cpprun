cmake_minimum_required(VERSION 2.8.9)

project (cpprun)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(cpprun src/cpprun.cpp)
target_link_libraries(cpprun stdc++fs)

install(TARGETS cpprun DESTINATION bin)
