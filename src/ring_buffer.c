#include "embetech/ring_buffer.h"

bool RingBuffer_Init(RingBuffer *instance, uint8_t *dataBuffer, size_t dataBufferSize) {
  if((NULL == instance) || (NULL == dataBuffer) || (0 == dataBufferSize)) {
    return false;
  }
  instance->dataBuffer = dataBuffer;
  instance->dataBufferSize = dataBufferSize;
  instance->count = 0;
  instance->head = dataBuffer;
  instance->tail = dataBuffer;
  return true;
}

bool RingBuffer_Clear(RingBuffer *instance) {
  if(NULL == instance) {
    return false;
  }
  instance->count = 0;
  instance->head = instance->dataBuffer;
  instance->tail = instance->dataBuffer;
  return true;
}

size_t RingBuffer_GetLen(RingBuffer const *instance) { return (instance != NULL) ? instance->count : 0U; }

bool RingBuffer_IsEmpty(RingBuffer const *instance) { return (0U == RingBuffer_GetLen(instance)); }

size_t RingBuffer_GetCapacity(RingBuffer const *instance) { return (instance != NULL) ? instance->dataBufferSize : 0U; }

size_t RingBuffer_GetSpace(RingBuffer const *instance) { return (instance != NULL) ? (size_t)(instance->dataBufferSize - instance->count) : 0U; }

bool RingBuffer_PutChar(RingBuffer *instance, uint8_t data) {
  if(0 == RingBuffer_GetSpace(instance)) {
    return false;
  }

  *instance->head = data;
  ++instance->count;
  ++instance->head;
  if(instance->head >= instance->dataBuffer + instance->dataBufferSize) {
    instance->head = instance->dataBuffer;
  }
  return true;
}

bool RingBuffer_GetChar(RingBuffer *instance, uint8_t *readData) {
  if(RingBuffer_IsEmpty(instance) || (NULL == readData)) {
    return false;
  }

  *readData = *instance->tail;
  instance->count--;
  instance->tail++;
  if(instance->tail >= instance->dataBuffer + instance->dataBufferSize) {
    instance->tail = instance->dataBuffer;
  }
  return true;
}
