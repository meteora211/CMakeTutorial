cmake_minimum_required(VERSION 3.10)

project(HELLO VERSION 0.1)

configure_file(cmaketutorial.h.in cmaketutorial.h)

add_executable(${PROJECT_NAME} main.cpp adder.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
