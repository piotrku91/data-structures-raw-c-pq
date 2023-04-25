#ifndef _PQQUEUE_H_
#define _PQQUEUE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

enum 
{
    MaxQueueSize = 100
};

typedef struct
{
    uint32_t max_size;
    uint32_t current_size;
    uint32_t head;
    uint32_t tail;
    void *element[MaxQueueSize];
} PqQueue;

void PqQueueInit(PqQueue *pq_queue, uint32_t max_size);
void PqQueueEnqueue(PqQueue *pq_queue, void *element);
void *PqQueueDequeue(PqQueue *pq_queue);
bool PqQueueIsFull(PqQueue *pq_queue);
bool PqQueueIsEmpty(PqQueue *pq_queue);

#endif /* _PQQUEUE_H_ */