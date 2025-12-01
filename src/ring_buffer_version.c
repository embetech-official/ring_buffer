#include "embetech/ring_buffer.h"

#ifndef RING_BUFFER_VERSION_MAJOR
#define RING_BUFFER_VERSION_MAJOR 0
#define RING_BUFFER_VERSION_MINOR 0
#define RING_BUFFER_VERSION_PATCH 0
#define RING_BUFFER_VERSION_ID 0
#define RING_BUFFER_VERSION "0.0.0-0"
#endif

SemanticVersion RingBuffer_GetVersion(void) {
  return (SemanticVersion){.major = (RING_BUFFER_VERSION_MAJOR),
                           .minor = (RING_BUFFER_VERSION_MINOR),
                           .patch = (RING_BUFFER_VERSION_PATCH),
                           .id = (RING_BUFFER_VERSION_ID)};
}

char const *RingBuffer_GetVersionString(void) { return (RING_BUFFER_VERSION); }
