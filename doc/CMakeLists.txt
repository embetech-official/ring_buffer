include(FindDoxygen)
find_package(Doxygen REQUIRED)

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
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ring_buffer_documentation)
set(DOXYGEN_GENERATE_TAGFILE ${DOXYGEN_OUTPUT_DIRECTORY}/html/embetech_ring_buffer.tag)
set(DOXYGEN_ALIASES
    [[purpose=@par Purpose:]] [[license=@par License:]] [[compiler=@par Compiler:]]
    [[ hardware=@par Hardware:]] [[comments=@par Comments:]] [[doc=@par Documented using:]]
)
set(DOXYGEN_WARN_AS_ERROR YES)

doxygen_add_docs(
  ring_buffer_doc ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src/include/embetech
  COMMENT "Generate documentation"
)
