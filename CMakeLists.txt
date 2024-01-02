cmake_minimum_required(VERSION 3.20)

project(
  ring_buffer
  VERSION 1.0.0
  LANGUAGES C)

option(CONFIG_RING_BUFFER_16_ENABLE "Build 16-bit version of ring buffer" ON)

option(CONFIG_RING_BUFFER_BUILD_TESTS "Forces building test cases" OFF)

add_subdirectory(src)

if(PROJECT_IS_TOP_LEVEL OR CONFIG_RING_BUFFER_BUILD_TESTS)
  add_subdirectory(tests)
endif()
