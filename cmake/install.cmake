include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

set(METADATA_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/ring_buffer)

install(TARGETS ring_buffer EXPORT ring_buffer-targets ARCHIVE FILE_SET HEADERS)
install(EXPORT ring_buffer-targets NAMESPACE embetech:: DESTINATION ${METADATA_DIR})

write_basic_package_version_file(ring_buffer-version.cmake COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/ring_buffer-config_template.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config.cmake INSTALL_DESTINATION ${METADATA_DIR}
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-version.cmake DESTINATION ${METADATA_DIR}
)

install(SCRIPT ${CMAKE_CURRENT_LIST_DIR}/install_header_licenses.cmake)
