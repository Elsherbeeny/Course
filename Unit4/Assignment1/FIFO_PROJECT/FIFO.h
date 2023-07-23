#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <stdint.h>

//to change the number of bits 
typedef  uint8_t FIFO_T;

typedef struct {
    FIFO_T* base;
    FIFO_T* tail;
    FIFO_T* head;
    unsigned int count;
    unsigned int length;
}FIFO_BUFFER_T;

typedef enum {
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL,
    FIFO_NOERROR,
    FIFO_ERROR
}FIFO_STATUS;

FIFO_STATUS FIFO_Enqueue ( FIFO_BUFFER_T* FIFO_buf , FIFO_T item );
FIFO_STATUS FIFO_Dequeue ( FIFO_BUFFER_T* FIFO_buf , FIFO_T* item );
FIFO_STATUS FIFO_INIT ( FIFO_BUFFER_T* FIFO_buf , FIFO_T* buf , uint32_t length);
FIFO_STATUS FIFO_IS_FULL ( FIFO_BUFFER_T* FIFO_buf );
FIFO_STATUS FIFO_IS_EMPTY( FIFO_BUFFER_T* FIFO_buf );









#endif