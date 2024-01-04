cmake_minimum_required(VERSION 3.20)

project(ring_buffer VERSION 1.0.0 LANGUAGES C)

option(CONFIG_RING_BUFFER_16_ENABLE "Build 16-bit version of ring buffer" ON)
option(CONFIG_RING_BUFFER_TESTS "Configures test cases" ${PROJECT_IS_TOP_LEVEL})
option(CONFIG_RING_BUFFER_INSTALL"Configures install target" ${PROJECT_IS_TOP_LEVEL})

include(requirements.cmake)

add_subdirectory(src)

if (CONFIG_RING_BUFFER_TESTS)
  enable_testing()
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()
