#ifndef _PQ_STACK_
#define _PQ_STACK_
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* PqStack - My own implementation of stack based on array
   Piotr K. (dajmosster@gmail.com)
   piotrq.eu
*/

#define MAXSTACKSIZE 1024
#define STACKEMPTYINDEX -1

/* Use this macro to define type of elements PqStack - default is uint8_t */
#ifndef PQSTACKDATATYPE 
#define PQSTACKDATATYPE uint8_t
#endif

typedef struct
{
   PQSTACKDATATYPE stack_table[MAXSTACKSIZE];
   int16_t stack_top;
} PqStack;

/**
 * @brief Initialize PqStack
 * 
 * @param PqStack PqStack struct instance 
 */
void PqStackInit(PqStack* pq_stack);

/**
 * @brief Push new element to PqStack
 * 
 * @param pq_stack PqStack struct instance 
 * @param data Element ot push on the top
 */
void PqStackPush(PqStack* pq_stack, PQSTACKDATATYPE data);

/**
 * @brief Pop last element from PqStack
 * 
 * @param pq_stack PqStack struct instance
 */
void PqStackPop(PqStack* pq_stack);

/**
 * @brief Gets last element from PqStack
 * 
 * @param pq_stack PqStack struct instance
 * @return const PQSTACKDATATYPE* Constant pointer to the last element on the top
 */
const PQSTACKDATATYPE* PqStackTop(PqStack* pq_stack);

/**
 * @brief Returns current size of amount elements on the stack
 * 
 * @param pq_stack 
 * @return uint32_t Amount of elements on the stack
 */
uint32_t PqStackCurrentSize(PqStack* pq_stack);

/**
 * @brief Returns if stack is empty
 * 
 * @param pq_stack PqStack struct instance
 */
bool PqStackIsEmpty(PqStack* pq_stack);

/**
 * @brief Returns if stack is full
 * 
 * @param pq_stack PqStack struct instance
 */
bool PqStackIsFull(PqStack* pq_stack);

#endif /* _PQ_STACK_ */