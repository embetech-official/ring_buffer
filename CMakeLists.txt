cmake_minimum_required(VERSION 3.25)

project(ring_buffer VERSION 1.0.0)

option(RING_BUFFER_TESTS "Configure unit tests target" OFF)
option(RING_BUFFER_DOC "Configure documentation target" OFF)
option(RING_BUFFER_EXAMPLES "Configure examples target" OFF)
option(RING_BUFFER_INSTALL "Configure install target" ON)

add_subdirectory(src)

if (RING_BUFFER_TESTS OR PROJECT_IS_TOP_LEVEL)
  enable_testing()
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()

if (RING_BUFFER_EXAMPLES OR PROJECT_IS_TOP_LEVEL)
  add_subdirectory(examples EXCLUDE_FROM_ALL)
endif ()

if (RING_BUFFER_DOC OR PROJECT_IS_TOP_LEVEL)
  add_subdirectory(doc EXCLUDE_FROM_ALL)
endif ()
