#include "embetech/ring_buffer.h"

bool RingBuffer_Init(RingBuffer *ringBuffer, uint8_t *dataBuffer, size_t dataBufferSize) {
  if((NULL == ringBuffer) || (NULL == dataBuffer) || (0 == dataBufferSize)) {
    return false;
  }
  ringBuffer->dataBuffer = dataBuffer;
  ringBuffer->dataBufferSize = dataBufferSize;
  ringBuffer->count = 0;
  ringBuffer->head = dataBuffer;
  ringBuffer->tail = dataBuffer;
  return true;
}

bool RingBuffer_Clear(RingBuffer *ringBuffer) {
  if(NULL == ringBuffer) {
    return false;
  }
  ringBuffer->count = 0;
  ringBuffer->head = ringBuffer->dataBuffer;
  ringBuffer->tail = ringBuffer->dataBuffer;
  return true;
}

bool RingBuffer_IsEmpty(RingBuffer const *ringBuffer) { return (NULL == ringBuffer) || (0U == ringBuffer->count); }

size_t RingBuffer_GetLen(RingBuffer const *ringBuffer) { return (ringBuffer != NULL) ? ringBuffer->count : 0U; }

size_t RingBuffer_GetCapacity(RingBuffer const *ringBuffer) { return (ringBuffer != NULL) ? ringBuffer->dataBufferSize : 0U; }

size_t RingBuffer_GetSpace(RingBuffer const *ringBuffer) {
  return (ringBuffer != NULL) ? (size_t)(ringBuffer->dataBufferSize - ringBuffer->count) : 0U;
}

bool RingBuffer_PutChar(RingBuffer *ringBuffer, uint8_t data) {
  if(0 == RingBuffer_GetSpace(ringBuffer)) {
    return false;
  }

  *ringBuffer->head = data;
  ++ringBuffer->count;
  ++ringBuffer->head;
  if(ringBuffer->head >= ringBuffer->dataBuffer + ringBuffer->dataBufferSize) {
    ringBuffer->head = ringBuffer->dataBuffer;
  }
  return true;
}

bool RingBuffer_GetChar(RingBuffer *ringBuffer, uint8_t *data_buffer) {
  if(RingBuffer_IsEmpty(ringBuffer)) {
    return false;
  }

  *data_buffer = *ringBuffer->tail;
  ringBuffer->count--;
  ringBuffer->tail++;
  if(ringBuffer->tail >= ringBuffer->dataBuffer + ringBuffer->dataBufferSize) {
    ringBuffer->tail = ringBuffer->dataBuffer;
  }
  return true;
}
