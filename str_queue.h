#ifndef STR_QUEUE_H
#define STR_QUEUE_H

typedef struct STRQueue {
    int max_size;
    int size;
    char **buffers;
} STRQueue;

// Create a queue
STRQueue *strqueue_create(int size);

// Free the queue
void strqueue_delete(STRQueue *queue);

// Returns 1 if it's full, 0 otherwise
int strqueue_isfull(STRQueue *queue);

// Returns 1 if it's full, 0 otherwise
int strqueue_isempty(STRQueue *queue);

// Returns 1 if the element was added, 0 otherwise
// Note: it copies the element.
int strqueue_push(STRQueue *queue, char *buf, size_t bufSize);

// Returns 1 if a element was deleted, 0 otherwise
int strqueue_pop(STRQueue *queue);

#endif
