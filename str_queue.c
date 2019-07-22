#include <stdlib.h>
#include <string.h>
#include "str_queue.h"

STRQueue *strqueue_create(int size) {
    STRQueue *queue = (STRQueue*)malloc(sizeof(STRQueue));
    queue->max_size = size;
    queue->size = 0;
    queue->buffers = (char**)calloc(sizeof(char*), size);
}

void strqueue_delete(STRQueue *queue) {
    if(!queue)
        return;
    for(int i = 0; i < queue->size; i++) {
        free(queue->buffers[i]);
    }
    free(queue->buffers);
    free(queue);
}

int strqueue_isfull(STRQueue *queue) {
    if(!queue)
        return 0;
    if(queue->size == queue->max_size)
        return 1;
    return 0;
}

int strqueue_isempty(STRQueue *queue) {
    if(!queue)
        return 0;
    if(queue->size == 0)
        return 1;
    return 0;
}

int strqueue_push(STRQueue *queue, char *buf, size_t bufSize) {
    if(strqueue_isfull(queue)) {
        return 0;
    }
    queue->buffers[queue->size] = (char*)malloc(bufSize);
    memcpy(queue->buffers[queue->size], buf, bufSize);
    queue->size++;
    return 1;
}

int strqueue_pop(STRQueue *queue) {
    if(queue->size == 0)
        return 0;

    free(queue->buffers[queue->size]);
    queue->buffers[queue->size] = NULL;
    queue->size--;
    return 1;
}
