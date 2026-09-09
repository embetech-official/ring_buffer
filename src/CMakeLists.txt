add_library(ring_buffer STATIC)
add_library(embetech::ring_buffer ALIAS ring_buffer)

target_compile_features(ring_buffer PRIVATE c_std_99)

target_sources(
  ring_buffer
  PRIVATE ring_buffer.c ring_buffer_16bit.c ring_buffer_version.c
  PUBLIC FILE_SET
         HEADERS
         BASE_DIRS
         include
         FILES
         include/embetech/ring_buffer.h
         include/embetech/ring_buffer_16bit.h
)

include(${PROJECT_SOURCE_DIR}/cmake/versioning.cmake)
get_version_string(RING_BUFFER_VERSION_STRING VERSION ${PROJECT_VERSION})

target_compile_definitions(ring_buffer PRIVATE RING_BUFFER_VERSION="${RING_BUFFER_VERSION_STRING}")
