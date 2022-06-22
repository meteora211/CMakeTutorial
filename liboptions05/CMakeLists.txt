cmake_minimum_required(VERSION 3.10)

project(ADD)

configure_file(lib_configure.h.in lib_configure.h)

option(USE_XBYAK "use xybak to do add." ON)
option(USE_ADDER "use adder." ON)

find_library(MyOpenMPLib NAMES omp gomp DOC "libomp location")
find_path(MyOpenMPDir NAMES omp.h DOC "libomp includes")
if(MyOpenMPLib)
  message(WARNING "OpenMP Lib found! path = ${MyOpenMPLib}")
endif()
if(MyOpenMPDir)
  message(WARNING "OpenMP Path found! path = ${MyOpenMPDir}")
endif()

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)

if(USE_XBYAK)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/../submodules03/extern/xbyak/")
  # target_include_directories(${PROJECT_NAME}
  #   PUBLIC ../submodules03/extern/xbyak/
  # )
endif()

if(USE_ADDER)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/adder/")
  list(APPEND EXTRA_LIBS adder)
  list(APPEND EXTRA_LINKS adder)
endif()

message(STATUS "includes: ${EXTRA_INCLUDES}" )
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDES} ${PROJECT_BINARY_DIR})

target_link_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS})
