#include "queue_manager.h"
#include <stdio.h>

void QueueManagerInit(QueueManager *queue_manager, uint32_t max_size)
{
    queue_manager->max_size = max_size;
    queue_manager->tail = queue_manager->max_size - 1;

    queue_manager->current_size = 0;
    queue_manager->head = 0;
}

bool QueueManagerEnqueue(QueueManager *queue_manager)
{
    if (QueueManagerIsFull(queue_manager))
    {
        return false;
    };
    queue_manager->tail = QueueManagerGetNextIndex(queue_manager);
    queue_manager->current_size++;
    return true;
}

bool QueueManagerDequeue(QueueManager *queue_manager)
{
    if (QueueManagerIsEmpty(queue_manager))
    {
        return false;
    };
    queue_manager->head = (queue_manager->head + 1) % queue_manager->max_size;
    queue_manager->current_size--;
    return true;
}

uint32_t QueueManagerGetNextIndex(QueueManager *queue_manager)
{
    return (queue_manager->tail + 1) % queue_manager->max_size;
}

uint32_t QueueManagerGetFrontIndex(QueueManager *queue_manager)
{
    return queue_manager->head;
}

bool QueueManagerIsFull(QueueManager *queue_manager)
{
    return queue_manager->current_size == queue_manager->max_size;
}

bool QueueManagerIsEmpty(QueueManager *queue_manager)
{
    return queue_manager->current_size == 0;
}