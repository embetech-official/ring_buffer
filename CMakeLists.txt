cmake_minimum_required(VERSION 3.25)

project(ring_buffer VERSION 1.0.1)

option(RING_BUFFER_TESTS "Configure unit tests target" ${PROJECT_IS_TOP_LEVEL})
option(RING_BUFFER_DOC "Configure documentation target" ${PROJECT_IS_TOP_LEVEL})
option(RING_BUFFER_EXAMPLES "Configure examples target" ${PROJECT_IS_TOP_LEVEL})
option(RING_BUFFER_INSTALL "Configure install target" ON)

add_subdirectory(src)

if (RING_BUFFER_TESTS)
  include(CTest)
  add_subdirectory(tests EXCLUDE_FROM_ALL)
endif ()

if (RING_BUFFER_EXAMPLES)
  add_subdirectory(examples EXCLUDE_FROM_ALL)
endif ()

if (RING_BUFFER_DOC)
  add_subdirectory(doc EXCLUDE_FROM_ALL)
endif ()

if (RING_BUFFER_INSTALL)
  include(cmake/install.cmake)
endif ()
