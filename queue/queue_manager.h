#ifndef P_QUEUE_MANAGER_H_
#define P_QUEUE_MANAGER_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint32_t max_size;
    uint32_t current_size;
    uint32_t head;
    uint32_t tail;
} QueueManager;

/**
 * @brief Initialize QueueManager
 *
 * @param queue_manager Queue manager Instance
 * @param max_size Limit of array
 */
void QueueManagerInit(QueueManager *queue_manager, uint32_t max_size);

/**
 * @brief Add new element to back of the queue (Setting index to correct value)
 *
 * @param queue_manager Queue manager Instance
 */
bool QueueManagerEnqueue(QueueManager *queue_manager);

/**
 * @brief Remove element from the begin of the queue (Setting index to correct value)
 *
 * @param queue_manager Queue manager Instance
 */
bool QueueManagerDequeue(QueueManager *queue_manager);

/**
 * @brief Get front index (It is index of first element to get)
 *
 * @param queue_manager Queue manager Instance
 */
uint32_t QueueManagerGetFrontIndex(QueueManager *queue_manager);

/**
 * @brief Get next index (It will be next index after use QueueManagerEnqueue function)
 *
 * @param queue_manager Queue manager Instance
 */
uint32_t QueueManagerGetNextIndex(QueueManager *queue_manager);

/**
 * @brief Get information about queue is full
 *
 * @param queue_manager Queue manager Instance
 */
bool QueueManagerIsFull(QueueManager *queue_manager);

/**
 * @brief Get information about queue is empty
 *
 * @param queue_manager Queue manager Instance
 */
bool QueueManagerIsEmpty(QueueManager *queue_manager);

#endif /* P_QUEUE_MANAGER_H_ */