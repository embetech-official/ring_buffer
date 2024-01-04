# Ring Buffer

[![C++ Unit Tests](https://github.com/embetech-official/ring_buffer/actions/workflows/cpp_unit_tests.yml/badge.svg)](https://github.com/embetech-official/ring_buffer/actions/workflows/cpp_unit_tests.yml)

## Overview
Ring Buffer is a library providing circular buffer data structure

## Installation
The easiest way is to use built-in CMake FetchContent:

```cmake
include(FetchContent)
FetchContent_Declare(
    ring_buffer
    GIT_REPOSITORY https://github.com/embetech-official/ring_buffer
    GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(ring_buffer)

# ...

target_link_libraries(<your target> PRIVATE embetech::ring_buffer)
``````

## Configuration
- `CONFIG_RING_BUFFER_16_ENABLE` - Makes variant with 16-bit element available
