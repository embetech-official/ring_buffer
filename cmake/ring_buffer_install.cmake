include(CMakePackageConfigHelpers)

set(CMAKES_EXPORT_DIR cmake/ring_buffer)

write_basic_package_version_file(ring_buffer-config-version.cmake COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  ${PROJECT_SOURCE_DIR}/cmake/ring_buffer-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config.cmake INSTALL_DESTINATION ${CMAKES_EXPORT_DIR}
)

include(GNUInstallDirs)
install(TARGETS ring_buffer EXPORT ring_buffer_targets)

install(DIRECTORY include/embetech DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer-config-version.cmake
        DESTINATION ${CMAKES_EXPORT_DIR}
)

install(EXPORT ring_buffer_targets NAMESPACE embetech:: DESTINATION ${CMAKES_EXPORT_DIR})
