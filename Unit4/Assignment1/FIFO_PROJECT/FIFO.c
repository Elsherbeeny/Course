#include"FIFO.h"

FIFO_STATUS FIFO_Enqueue ( FIFO_BUFFER_T* FIFO_buf , FIFO_T item ){
    if(FIFO_IS_FULL(FIFO_buf)==FIFO_NOERROR){

    if(FIFO_buf->tail !=FIFO_buf->base)
        FIFO_buf->tail =FIFO_buf->base;

        *(FIFO_buf->head)=item;
        FIFO_buf->head++;
        FIFO_buf->count++;
        return FIFO_NOERROR;
    }else{
        printf("Enqueue faield");
        return FIFO_ERROR;
    }
    



}
FIFO_STATUS FIFO_Dequeue ( FIFO_BUFFER_T* FIFO_buf , FIFO_T* item ){
    if(FIFO_IS_EMPTY(FIFO_buf)==FIFO_NOERROR){
        if(FIFO_buf->tail==FIFO_buf->base +(FIFO_buf->length)*(sizeof(FIFO_T)))
        FIFO_buf->tail=FIFO_buf->head;
        *item=*(FIFO_buf->tail);
        FIFO_buf->tail++;
        FIFO_buf->count--;
        return FIFO_NOERROR;

    }else{
        printf("Dequeue failed");
        return FIFO_ERROR;
    }

}
FIFO_STATUS FIFO_INIT ( FIFO_BUFFER_T* FIFO_buf , FIFO_T* buf , uint32_t length){

    if(buf==NULL){
        return FIFO_NULL;
    }
    FIFO_buf->base=buf;
    FIFO_buf->head=buf;
    FIFO_buf->tail=buf;
    FIFO_buf->length=length;
    FIFO_buf->count =0;

}
FIFO_STATUS FIFO_IS_FULL ( FIFO_BUFFER_T* FIFO_buf ){
    if(!FIFO_buf->head ||!FIFO_buf->tail || !FIFO_buf->base){
        return FIFO_NULL;
    }
    if(FIFO_buf->count==FIFO_buf->length){
        return FIFO_FULL;

    }
    return FIFO_NOERROR;
}
FIFO_STATUS FIFO_IS_EMPTY( FIFO_BUFFER_T* FIFO_buf ){
    if(!FIFO_buf->head ||!FIFO_buf->tail || !FIFO_buf->base){
        return FIFO_NULL;
    }
    if(FIFO_buf->count==0){
        return FIFO_EMPTY;
    }
    return FIFO_NOERROR;
    
}