cmake_policy(SET CMP0135 NEW)

include(FetchContent)

if (CONFIG_RING_BUFFER_BUILD_TESTS)
  FetchContent_Declare(
    googletest URL https://github.com/google/googletest/archive/main.zip FIND_PACKAGE_ARGS NAMES
                   GTest
  )
endif ()
