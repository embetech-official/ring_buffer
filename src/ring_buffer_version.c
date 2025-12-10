#include "embetech/ring_buffer.h"
#include <assert.h>

#ifndef RING_BUFFER_VERSION
#error "RING_BUFFER_VERSION is not defined"
#endif

static_assert(sizeof(RING_BUFFER_VERSION) <= 64, "RING_BUFFER_VERSION too long"); // NOLINT(readability-magic-numbers) - 64 bytes max

char const *RingBuffer_GetVersionString(void) { return (RING_BUFFER_VERSION); }
