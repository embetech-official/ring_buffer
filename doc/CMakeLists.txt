find_package(Doxygen QUIET)
if (NOT Doxygen_FOUND)
  message(STATUS "Doxygen not found, documentation will not be generated")
  return()
endif ()

set(DOXYGEN_PROJECT_NAME "EMBETECH Ring Buffer")
set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
set(DOXYGEN_TIMESTAMP YES)
set(DOXYGEN_CASE_SENSE_NAMES NO)
set(DOXYGEN_SHOW_INCLUDE_FILES NO)
set(DOXYGEN_SORT_MEMBER_DOCS NO)
set(DOXYGEN_LAYOUT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/DoxygenLayout.xml)
set(DOXYGEN_EXAMPLE_PATH ${PROJECT_SOURCE_DIR}/examples)
set(DOXYGEN_REFERENCES_LINK_SOURCE NO)
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_VERBATIM_HEADERS NO)
set(DOXYGEN_HTML_COLORSTYLE DARK)
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/doc)
set(DOXYGEN_GENERATE_TAGFILE ${DOXYGEN_OUTPUT_DIRECTORY}/html/ring_buffer.tag)
set(DOXYGEN_ALIASES [[purpose=@par Purpose:]] [[license=@par License:]] [[compiler=@par Compiler:]] [[ hardware=@par Hardware:]]
                    [[comments=@par Comments:]] [[doc=@par Documented using:]]
)
set(DOXYGEN_WARN_AS_ERROR YES)

# Create local copy of public headers and configure VERSION and LICENSE information
include(${PROJECT_SOURCE_DIR}/cmake/install_header_licenses.cmake)
get_target_property(RING_BUFFER_PUBLIC_HEADER_DIR ring_buffer HEADER_DIRS)
get_target_property(RING_BUFFER_PUBLIC_HEADERS ring_buffer HEADER_SET)
set(RING_BUFFER_DOC_STAGED_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/staged_headers)
foreach (header ${RING_BUFFER_PUBLIC_HEADERS})
  file(RELATIVE_PATH relative_header ${RING_BUFFER_PUBLIC_HEADER_DIR} ${header})
  ring_buffer_configure_license_header(${header} ${RING_BUFFER_DOC_STAGED_HEADERS_DIR}/${relative_header})
endforeach ()

# Strip the staged/build paths so generated docs show clean header names instead of build/gcc*/doc/staged_headers/...
set(DOXYGEN_STRIP_FROM_PATH ${RING_BUFFER_DOC_STAGED_HEADERS_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

doxygen_add_docs(
  ring_buffer_doc ALL ${CMAKE_CURRENT_SOURCE_DIR} ${RING_BUFFER_DOC_STAGED_HEADERS_DIR}
  COMMENT "Generate documentation"
)
