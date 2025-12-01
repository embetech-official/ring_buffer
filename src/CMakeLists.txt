add_library(ring_buffer STATIC)
add_library(embetech::ring_buffer ALIAS ring_buffer)

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

target_link_libraries(ring_buffer PUBLIC embetech::utils)

if (PROJECT_IS_TOP_LEVEL)
  # Retrieve the commit ID from the Git repository
  find_package(Git REQUIRED)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} -C ${CMAKE_SOURCE_DIR} rev-parse --short=8 HEAD
    OUTPUT_VARIABLE COMMIT_ID OUTPUT_STRIP_TRAILING_WHITESPACE
  )
  message(VERBOSE "Commit ID: ${COMMIT_ID}")
else ()
  # Ingrown build. Do not use meaningful commit ID
  set(COMMIT_ID 0)
endif ()

target_compile_definitions(
  ring_buffer
  PRIVATE RING_BUFFER_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
          RING_BUFFER_VERSION_MINOR=${PROJECT_VERSION_MINOR}
          RING_BUFFER_VERSION_PATCH=${PROJECT_VERSION_PATCH}
          RING_BUFFER_VERSION_ID=0x${COMMIT_ID}
          RING_BUFFER_VERSION=\"${PROJECT_VERSION}-${COMMIT_ID}\"
)
