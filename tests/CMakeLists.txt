include(GoogleTest)

# Workaround for https://github.com/google/googletest/issues/4671
target_compile_options(gtest PRIVATE -Wno-null-dereference)


add_executable(ring_buffer_ut ring_buffer_ut.cpp)

target_link_libraries(ring_buffer_ut PRIVATE embetech::ring_buffer GTest::gtest_main)
gtest_discover_tests(ring_buffer_ut)
