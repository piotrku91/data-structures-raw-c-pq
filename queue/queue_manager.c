#include "queue_manager.h"
#include <stdio.h>

void QueueManagerInit(QueueManager *pq_queue, uint32_t max_size)
{
    pq_queue->max_size = max_size;
    pq_queue->tail = pq_queue->max_size - 1;

    pq_queue->current_size = 0;
    pq_queue->head = 0;
}

bool QueueManagerEnqueue(QueueManager *pq_queue)
{
    if (QueueManagerIsFull(pq_queue))
    {
        return false;
    };
    pq_queue->tail = QueueManagerGetNextIndex(pq_queue);
    pq_queue->current_size++;
    return true;
}

bool QueueManagerDequeue(QueueManager *pq_queue)
{
    if (QueueManagerIsEmpty(pq_queue))
    {
        return false;
    };
    pq_queue->head = (pq_queue->head + 1) % pq_queue->max_size;
    pq_queue->current_size--;
    return true;
}

uint32_t QueueManagerGetNextIndex(QueueManager *pq_queue)
{
    return (pq_queue->tail + 1) % pq_queue->max_size;
}

uint32_t QueueManagerGetFrontIndex(QueueManager *pq_queue)
{
    return pq_queue->head;
}

bool QueueManagerIsFull(QueueManager *pq_queue)
{
    return pq_queue->current_size == pq_queue->max_size;
}

bool QueueManagerIsEmpty(QueueManager *pq_queue)
{
    return pq_queue->current_size == 0;
}