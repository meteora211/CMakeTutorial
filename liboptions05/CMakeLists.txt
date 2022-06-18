cmake_minimum_required(VERSION 3.10)

project(ADD)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)

target_include_directories(${PROJECT_NAME}
  PUBLIC adder/
  PUBLIC ../submodules03/extern/xbyak/
)

target_link_directories(${PROJECT_NAME}
  PRIVATE adder/
)

target_link_libraries(${PROJECT_NAME} adder)
