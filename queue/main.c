#include <stdio.h>
#include "pqqueue.h"
#include "queue_manager.h"

void queue()
{
    PqQueue queue;
    uint8_t tab[7] = {1, 2, 3, 4, 5, 6, 7};

    PqQueueInit(&queue, tab, 5);

    printf("empty %d \n", PqQueueIsEmpty(&queue));
    printf("full %d \n", PqQueueIsFull(&queue));

    PqQueueEnqueue(&queue, 0);
    PqQueueEnqueue(&queue, 1);
    PqQueueEnqueue(&queue, 2);
    PqQueueEnqueue(&queue, 3);

    printf("empty %d \n", PqQueueIsEmpty(&queue));
    printf("full %d \n", PqQueueIsFull(&queue));

    PqQueueEnqueue(&queue, 4);
    PqQueueEnqueue(&queue, 5);

    printf("empty %d \n", PqQueueIsEmpty(&queue));
    printf("full %d \n", PqQueueIsFull(&queue));

    printf("el %d \n", *((uint8_t *)PqQueueDequeue(&queue)));

    printf("empty %d \n", PqQueueIsEmpty(&queue));
    printf("full %d \n", PqQueueIsFull(&queue));

    printf("el %d \n", *((uint8_t *)PqQueueDequeue(&queue)));
}

void queuemanager()
{
    QueueManager queue;
    QueueManagerInit(&queue, 5);
    uint8_t tab[7] = {0};

    for (int i = 0; i < 10; i++)
    {
        if (!QueueManagerIsFull(&queue))
        {
            
            uint32_t next_index = QueueManagerGetNextIndex(&queue);
            tab[next_index] = i;
            QueueManagerEnqueue(&queue);
            printf("next index %d \n", next_index);
            printf("element %d \n\n", tab[next_index]);
        }
    };

    printf("element %d \n", tab[QueueManagerGetFrontIndex(&queue)]);
    printf("front index %d \n", QueueManagerGetFrontIndex(&queue));
    printf("next index %d \n", QueueManagerGetNextIndex(&queue));
    printf("empty %d \n", QueueManagerIsEmpty(&queue));
    printf("full %d \n\n", QueueManagerIsFull(&queue));

    QueueManagerDequeue(&queue);
    printf("element %d \n", tab[QueueManagerGetFrontIndex(&queue)]);
    printf("front index %d \n", QueueManagerGetFrontIndex(&queue));
    printf("next index %d \n", QueueManagerGetNextIndex(&queue));
    printf("empty %d \n", QueueManagerIsEmpty(&queue));
    printf("full %d \n\n", QueueManagerIsFull(&queue));

    QueueManagerDequeue(&queue);
    printf("element %d \n", tab[QueueManagerGetFrontIndex(&queue)]);
    printf("front index %d \n", QueueManagerGetFrontIndex(&queue));
    printf("next index %d \n", QueueManagerGetNextIndex(&queue));
    printf("empty %d \n", QueueManagerIsEmpty(&queue));
    printf("full %d \n\n", QueueManagerIsFull(&queue));

    QueueManagerEnqueue(&queue);

    QueueManagerDequeue(&queue);
    printf("element %d \n", tab[QueueManagerGetFrontIndex(&queue)]);
    printf("front index %d \n", QueueManagerGetFrontIndex(&queue));
    printf("next index %d \n", QueueManagerGetNextIndex(&queue));
    printf("empty %d \n", QueueManagerIsEmpty(&queue));
    printf("full %d \n\n", QueueManagerIsFull(&queue));

    QueueManagerDequeue(&queue);
    printf("element %d \n", tab[QueueManagerGetFrontIndex(&queue)]);
    printf("front index %d \n", QueueManagerGetFrontIndex(&queue));
    printf("next index %d \n", QueueManagerGetNextIndex(&queue));
    printf("empty %d \n", QueueManagerIsEmpty(&queue));
    printf("full %d \n\n", QueueManagerIsFull(&queue));

}

int main(void)
{
  //  queue();
    queuemanager();
}
