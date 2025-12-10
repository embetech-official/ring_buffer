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

if (PROJECT_IS_TOP_LEVEL)
  include(${PROJECT_SOURCE_DIR}/cmake/git_utils.cmake)
  get_git_commit_id(RING_BUFFER_COMMIT_ID REQUIRED LENGTH 8)
endif ()

if (NOT RING_BUFFER_COMMIT_ID)
  set(RING_BUFFER_COMMIT_ID "local") # Fallback for out of tree builds
endif ()

target_compile_definitions(ring_buffer PRIVATE RING_BUFFER_VERSION="${PROJECT_VERSION}+${RING_BUFFER_COMMIT_ID}")
