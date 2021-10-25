cmake_minimum_required(VERSION 3.17)
project(Racuni_2_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(Racuni_2_0 main.cpp)
configure_file(input.txt input.txt COPYONLY)