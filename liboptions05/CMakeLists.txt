cmake_minimum_required(VERSION 3.10)

project(ADD)

configure_file(lib_configure.h.in lib_configure.h)

option(USE_XBYAK "use xybak to do add." ON)
option(USE_ADDER "use adder." ON)

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
endif()

message(STATUS "includes: ${EXTRA_INCLUDES}" )
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDES} ${PROJECT_BINARY_DIR})

target_link_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

target_link_libraries(${PROJECT_NAME} adder)
