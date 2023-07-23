#include"lifo.h"
#include<stdio.h>

LIFO_STATUS LIFO_INIT (LIFO_BUFFER_T* LIFO_BUFFER,LIFO_T* buf ,unsigned int length){

    if(buf ==NULL){
        return LIFO_NULL;
    }

    LIFO_BUFFER->base=buf;
    LIFO_BUFFER->head=buf;
    LIFO_BUFFER->count=0;
    LIFO_BUFFER->length=length;
    
    return LIFO_NOERROR;


}
LIFO_STATUS LIFO_PUSH (LIFO_BUFFER_T* LIFO_BUFFER,LIFO_T item){

    if(!LIFO_BUFFER->head || !LIFO_BUFFER->base){
        return LIFO_NULL;
    }
    if(LIFO_BUFFER->count==LIFO_BUFFER->length){
        return LIFO_FULL;
    }
    *(LIFO_BUFFER->head)=item;
    LIFO_BUFFER->head++;
    LIFO_BUFFER->count++;
    return LIFO_NOERROR;



}
LIFO_STATUS LIFO_POP (LIFO_BUFFER_T* LIFO_BUFFER,unsigned int* item){
     if(!LIFO_BUFFER->head || !LIFO_BUFFER->base){
        return LIFO_NULL;
    }
    if(LIFO_BUFFER->count ==0){
        return LIFO_EMPTY;
    }
    LIFO_BUFFER->head--;
    *item= *(LIFO_BUFFER->head);
    LIFO_BUFFER->count--;
    return LIFO_NOERROR;

}