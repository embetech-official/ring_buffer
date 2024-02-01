project(ring_buffer_ut)


include(FetchContent)

FetchContent_Declare(
  googletest URL https://github.com/google/googletest/archive/main.zip FIND_PACKAGE_ARGS NAMES
                 GTest
)

FetchContent_MakeAvailable(googletest)

add_executable(ring_buffer_ut ring_buffer_ut.cpp)
target_link_libraries(ring_buffer_ut PRIVATE embetech::ring_buffer gtest_main)
include(GoogleTest)
gtest_discover_tests(ring_buffer_ut)
