#include "pqqueue.h"

void PqQueueInit(PqQueue *pq_queue, PQQUEUETYPE* queue_array, uint32_t max_size)
{
    pq_queue->elements = queue_array;
    pq_queue->max_size = max_size;
    pq_queue->tail = pq_queue->max_size - 1;

    pq_queue->current_size = 0;
    pq_queue->head = 0;
}

void PqQueueEnqueueByPtr(PqQueue *pq_queue, PQQUEUETYPE* element)
{
    if (PqQueueIsFull(pq_queue))
    {
        return;
    };
    pq_queue->tail = (pq_queue->tail + 1) % pq_queue->max_size;
    pq_queue->elements[pq_queue->tail] = *element;
    pq_queue->current_size++;
}

void PqQueueEnqueue(PqQueue *pq_queue, PQQUEUETYPE element)
{
    if (PqQueueIsFull(pq_queue))
    {
        return;
    };
    pq_queue->tail = (pq_queue->tail + 1) % pq_queue->max_size;
    pq_queue->elements[pq_queue->tail] = element;
    pq_queue->current_size++;
}

PQQUEUETYPE* PqQueueDequeue(PqQueue *pq_queue)
{
    if (PqQueueIsEmpty(pq_queue))
    {
        return NULL;
    };
    PQQUEUETYPE* out_element = &pq_queue->elements[pq_queue->head];
    pq_queue->head = (pq_queue->head + 1) % pq_queue->max_size;
    pq_queue->current_size--;
    return out_element;
}

PQQUEUETYPE* PqQueueFront(PqQueue *pq_queue)
{
    if (PqQueueIsEmpty(pq_queue))
    {
        return NULL;
    };
    return &pq_queue->elements[pq_queue->head];
}

bool PqQueueIsFull(PqQueue *pq_queue)
{
    return pq_queue->current_size == pq_queue->max_size;
}

bool PqQueueIsEmpty(PqQueue *pq_queue)
{
    return pq_queue->current_size == 0;
}