add_library(ring_buffer STATIC ring_buffer.c)
target_include_directories(
  ring_buffer PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/embetech>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)

add_library(embetech::ring_buffer ALIAS ring_buffer)

if (CONFIG_RING_BUFFER_16_ENABLE)
  target_sources(ring_buffer PRIVATE ring_buffer_16bit.c)
endif ()

include(${PROJECT_SOURCE_DIR}/cmake/component-install.cmake)