cmake_minimum_required(VERSION 3.16)
project(hellocmake LANGUAGES CXX)

add_executable(prog main.cpp print_hello.cpp sum_to.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

install(TARGETS prog DESTINATION ${CMAKE_SOURCE_DIR}/bin)