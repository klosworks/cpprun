cmake_minimum_required(VERSION 2.8.9)

project (cpprun)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

find_package (Threads)

include_directories("cpp-subprocess")
include_directories(fmt/include)
add_subdirectory(fmt)

add_executable(cpprun src/cpprun.cpp fmt/src/format.cc fmt/src/posix.cc)
target_link_libraries(cpprun stdc++fs ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS cpprun DESTINATION bin)
