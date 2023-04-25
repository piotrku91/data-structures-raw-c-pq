#include <stdio.h>
#include "pqqueue.h"

void queue()
{
PqQueue queue;
uint8_t tab[7] = {1,2,3,4,5,6,7};

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

printf("el %d \n", *((uint8_t*)PqQueueDequeue(&queue)));

printf("empty %d \n", PqQueueIsEmpty(&queue));
printf("full %d \n", PqQueueIsFull(&queue));

printf("el %d \n", *((uint8_t*)PqQueueDequeue(&queue)));
}

int main(void)
{
queue();
}
