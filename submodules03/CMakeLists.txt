cmake_minimum_required(VERSION 3.10)

project(hello)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)

find_package(Git)
if(Git_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/../.git")
  option(GIT_SUBMODULE "CHECK submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}")
    endif()
  endif()
endif()
add_subdirectory(extern/xbyak)

target_include_directories(${PROJECT_NAME}
  PUBLIC adder/
  PUBLIC extern/xbyak/
)

target_link_directories(${PROJECT_NAME}
  PRIVATE adder/
)

target_link_libraries(${PROJECT_NAME} adder)
