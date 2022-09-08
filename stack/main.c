#include <stdio.h>
#include "pqstack.h"

void print_top(PqStack *pq_stack)
{
    if (!PqStackIsEmpty(pq_stack))
    {
       uint8_t top_element = *PqStackTop(pq_stack);
       printf("%d\n", top_element);
    }
    else
    {
        printf("Stack is empty\n");
    }
}

int main(void)
{
    PqStack pq_stack;

    PqStackInit(&pq_stack);

    PqStackPush(&pq_stack, 42);
    PqStackPush(&pq_stack, 32);
    PqStackPush(&pq_stack, 81);
    PqStackPop(&pq_stack);

    print_top(&pq_stack);

    PqStackPop(&pq_stack);
    PqStackPop(&pq_stack);

    print_top(&pq_stack);
    
}