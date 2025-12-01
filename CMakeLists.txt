cmake_minimum_required(VERSION 3.25)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" PROJECT_VERSION)
project(ring_buffer VERSION  ${PROJECT_VERSION})

option(RING_BUFFER_TESTS "Configure unit tests target" ${PROJECT_IS_TOP_LEVEL})
option(RING_BUFFER_DOC "Configure documentation target" ${PROJECT_IS_TOP_LEVEL})
option(RING_BUFFER_EXAMPLES "Configure examples target" ${PROJECT_IS_TOP_LEVEL})
option(RING_BUFFER_INSTALL "Configure install target" ON)

add_subdirectory(src)

include(cmake/requirements.cmake)

if (RING_BUFFER_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif ()

if (RING_BUFFER_EXAMPLES)
  add_subdirectory(examples)
endif ()

if (RING_BUFFER_DOC)
  add_subdirectory(doc)
endif ()

if (RING_BUFFER_INSTALL)
  include(cmake/install.cmake)
endif ()
