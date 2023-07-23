#ifndef LIFO_H
#define LIFO_H

typedef unsigned int LIFO_T;

typedef struct 
{
    LIFO_T* base;
    LIFO_T* head;
    unsigned int count;
    unsigned int length;
}LIFO_BUFFER_T;

typedef enum {
    LIFO_EMPTY,
    LIFO_FULL,
    LIFO_NULL,
    LIFO_NOERROR

}LIFO_STATUS;

//APIS

LIFO_STATUS LIFO_INIT (LIFO_BUFFER_T* LIFO_BUFFER,LIFO_T* buf ,unsigned int length);
LIFO_STATUS LIFO_PUSH (LIFO_BUFFER_T* LIFO_BUFFER,LIFO_T item);
LIFO_STATUS LIFO_POP (LIFO_BUFFER_T* LIFO_BUFFFER,unsigned int* item);
#endif
