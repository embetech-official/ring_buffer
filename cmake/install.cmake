include(CMakePackageConfigHelpers)

set(METADATA_DIR cmake)
set(INCLUDE_DIR include)
set(LIBRARY_DIR lib/${CMAKE_LIBRARY_ARCHITECTURE})

set(PROJECT_LICENSE "commercial")
set(PROJECT_COPYRIGHT "Embetech sp. z o.o.")

write_basic_package_version_file(ring_buffer-config-version.cmake COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/cmake/ring_buffer-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config.cmake INSTALL_DESTINATION ${METADATA_DIR}
)

install(TARGETS ring_buffer EXPORT ring_buffer_targets ARCHIVE DESTINATION ${LIBRARY_DIR})

install(DIRECTORY src/include/embetech DESTINATION ${INCLUDE_DIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config-version.cmake
        DESTINATION ${METADATA_DIR}
)

install(EXPORT ring_buffer_targets NAMESPACE embetech:: DESTINATION ${METADATA_DIR})
