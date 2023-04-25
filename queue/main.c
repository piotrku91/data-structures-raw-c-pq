#include <stdio.h>
#include "pqqueue.h"

int main(void)
{
PqQueue queue;
PqQueueInit(&queue, 5);

int tab[7] = {1,2,3,4,5,6,7};

printf("empty %d \n", PqQueueIsEmpty(&queue));
printf("full %d \n", PqQueueIsFull(&queue));

PqQueueEnqueue(&queue, &tab[0]);
PqQueueEnqueue(&queue, &tab[1]);
PqQueueEnqueue(&queue, &tab[2]);
PqQueueEnqueue(&queue, &tab[3]);

printf("empty %d \n", PqQueueIsEmpty(&queue));
printf("full %d \n", PqQueueIsFull(&queue));

PqQueueEnqueue(&queue, &tab[4]);
PqQueueEnqueue(&queue, &tab[5]);

printf("empty %d \n", PqQueueIsEmpty(&queue));
printf("full %d \n", PqQueueIsFull(&queue));

printf("el %d \n", *((uint8_t*)PqQueueDequeue(&queue)));

printf("empty %d \n", PqQueueIsEmpty(&queue));
printf("full %d \n", PqQueueIsFull(&queue));

printf("el %d \n", *((uint8_t*)PqQueueDequeue(&queue)));
}