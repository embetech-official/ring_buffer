# Ring Buffer

[![CI Tests](https://github.com/embetech-official/ring_buffer/actions/workflows/on_push.yml/badge.svg)](https://github.com/embetech-official/ring_buffer/actions/workflows/on_push.yml)
![GitHub License](https://img.shields.io/github/license/embetech-official/ring_buffer)
![GitHub Release](https://img.shields.io/github/v/release/embetech-official/ring_buffer)

## Overview

Ring Buffer is a library providing circular buffer data structure

## Quick Start

The easiest way to fetch this component is to use [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake).
In your CMakeLists.txt add:

```cmake
  CPMAddPackage("gh:embetech-official/ring_buffer@1")
```

Then add link dependency

```cmake
target_link_libraries(<your target> PRIVATE embetech::ring_buffer)
```
