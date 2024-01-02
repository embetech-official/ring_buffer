project(ring_buffer_ut LANGUAGES CXX C)

FetchContent_MakeAvailable(googletest)

add_executable(ring_buffer_ut ring_buffer_ut.cpp)
target_link_libraries(ring_buffer_ut PRIVATE embetech::ring_buffer gtest_main)
include(GoogleTest)
gtest_discover_tests(ring_buffer_ut)
