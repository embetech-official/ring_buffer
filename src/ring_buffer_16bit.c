#include "embetech/ring_buffer_16bit.h"

bool RingBuffer16Bit_Init(RingBuffer16Bit *ringBuffer, uint16_t *dataBuffer, size_t dataBufferSize) {
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

bool RingBuffer16Bit_Clear(RingBuffer16Bit *ringBuffer) {
  if(NULL == ringBuffer) {
    return false;
  }
  ringBuffer->count = 0;
  ringBuffer->head = ringBuffer->dataBuffer;
  ringBuffer->tail = ringBuffer->dataBuffer;
  return true;
}

size_t RingBuffer16Bit_GetLen(RingBuffer16Bit const *ringBuffer) { return (ringBuffer != NULL) ? ringBuffer->count : 0U; }

bool RingBuffer16Bit_IsEmpty(RingBuffer16Bit const *ringBuffer) { return (0U == RingBuffer16Bit_GetLen(ringBuffer)); }

size_t RingBuffer16Bit_GetCapacity(RingBuffer16Bit const *ringBuffer) { return (ringBuffer != NULL) ? ringBuffer->dataBufferSize : 0U; }

size_t RingBuffer16Bit_GetSpace(RingBuffer16Bit const *ringBuffer) {
  return (ringBuffer != NULL) ? (size_t)(ringBuffer->dataBufferSize - ringBuffer->count) : 0U;
}

bool RingBuffer16Bit_PutChar(RingBuffer16Bit *ringBuffer, uint16_t c) {
  if(0 == RingBuffer16Bit_GetSpace(ringBuffer)) {
    return false;
  }
  *ringBuffer->head = c;
  ringBuffer->count++;
  ringBuffer->head++;
  if(ringBuffer->head >= ringBuffer->dataBuffer + ringBuffer->dataBufferSize) {
    ringBuffer->head = ringBuffer->dataBuffer;
  }
  return true;
}

bool RingBuffer16Bit_GetChar(RingBuffer16Bit *ringBuffer, uint16_t *data_buffer) {
  if(RingBuffer16Bit_IsEmpty(ringBuffer) || (NULL == data_buffer)) {
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
