add_library(ring_buffer STATIC ring_buffer.c ring_buffer_16bit.c)
target_include_directories(
  ring_buffer PRIVATE
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/embetech>
)

add_library(embetech::ring_buffer ALIAS ring_buffer)

