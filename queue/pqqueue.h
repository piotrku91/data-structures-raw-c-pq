#ifndef _PQQUEUE_H_
#define _PQQUEUE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

enum 
{
    MaxQueueSize = 100
};

#ifndef PQQUEUETYPE
/* Use this macro to define type of elements PqLinkedList - default is uint8_t */
#define PQQUEUETYPE uint8_t
#endif

typedef struct
{
    uint32_t max_size;
    uint32_t current_size;
    uint32_t head;
    uint32_t tail;
    PQQUEUETYPE* elements;
} PqQueue;

void PqQueueInit(PqQueue *pq_queue, PQQUEUETYPE* queue_array, uint32_t max_size);
void PqQueueEnqueue(PqQueue *pq_queue, PQQUEUETYPE element);
void PqQueueEnqueueByPtr(PqQueue *pq_queue, PQQUEUETYPE* element);
PQQUEUETYPE *PqQueueDequeue(PqQueue *pq_queue);
PQQUEUETYPE* PqQueueFront(PqQueue *pq_queue);
bool PqQueueIsFull(PqQueue *pq_queue);
bool PqQueueIsEmpty(PqQueue *pq_queue);

#endif /* _PQQUEUE_H_ */