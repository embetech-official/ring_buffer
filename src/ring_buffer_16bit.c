#include "embetech/ring_buffer_16bit.h"

bool RingBuffer16Bit_Init(RingBuffer16Bit *instance, uint16_t *dataBuffer, size_t dataBufferSize) {
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

bool RingBuffer16Bit_Clear(RingBuffer16Bit *instance) {
  if(NULL == instance) {
    return false;
  }
  instance->count = 0;
  instance->head = instance->dataBuffer;
  instance->tail = instance->dataBuffer;
  return true;
}

size_t RingBuffer16Bit_GetLen(RingBuffer16Bit const *instance) { return (instance != NULL) ? instance->count : 0U; }

bool RingBuffer16Bit_IsEmpty(RingBuffer16Bit const *instance) { return (0U == RingBuffer16Bit_GetLen(instance)); }

size_t RingBuffer16Bit_GetCapacity(RingBuffer16Bit const *instance) { return (instance != NULL) ? instance->dataBufferSize : 0U; }

size_t RingBuffer16Bit_GetSpace(RingBuffer16Bit const *instance) {
  return (instance != NULL) ? (size_t)(instance->dataBufferSize - instance->count) : 0U;
}

bool RingBuffer16Bit_PutChar(RingBuffer16Bit *instance, uint16_t data) {
  if(0 == RingBuffer16Bit_GetSpace(instance)) {
    return false;
  }
  *instance->head = data;
  instance->count++;
  instance->head++;
  if(instance->head >= instance->dataBuffer + instance->dataBufferSize) {
    instance->head = instance->dataBuffer;
  }
  return true;
}

bool RingBuffer16Bit_GetChar(RingBuffer16Bit *instance, uint16_t *readData) {
  if(RingBuffer16Bit_IsEmpty(instance) || (NULL == readData)) {
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
