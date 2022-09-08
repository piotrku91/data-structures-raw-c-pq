#include "pqstack.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PqStackInit(PqStack *pq_stack)
{
    pq_stack->stack_top = STACKEMPTYINDEX;

    for (uint32_t i = 0; i < MAXSTACKSIZE; i++)
    {
        pq_stack->stack_table[0] = 0;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PqStackPush(PqStack *pq_stack, PQSTACKDATATYPE data)
{
    if (PqStackIsFull(pq_stack))
    {
        return;
    };
    pq_stack->stack_table[++pq_stack->stack_top] = data;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PqStackPop(PqStack *pq_stack)
{
    if (PqStackIsEmpty(pq_stack))
    {
        return;
    };
    pq_stack->stack_top--;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const PQSTACKDATATYPE *PqStackTop(PqStack *pq_stack)
{
    if (PqStackIsEmpty(pq_stack))
    {
        return NULL;
    };
    return &pq_stack->stack_table[pq_stack->stack_top];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t PqStackCurrentSize(PqStack *pq_stack)
{
    return pq_stack->stack_top + 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqStackIsEmpty(PqStack *pq_stack)
{
    return pq_stack->stack_top == STACKEMPTYINDEX;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqStackIsFull(PqStack *pq_stack)
{
    return pq_stack->stack_top == MAXSTACKSIZE - 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////