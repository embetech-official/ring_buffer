add_library(ring_buffer STATIC ring_buffer.c ring_buffer_16bit.c)
target_include_directories(
  ring_buffer PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/embetech>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)

add_library(embetech::ring_buffer ALIAS ring_buffer)

if (RING_BUFFER_INSTALL OR PROJECT_IS_TOP_LEVEL)
  include(${PROJECT_SOURCE_DIR}/cmake/ring_buffer_install.cmake)
endif ()
