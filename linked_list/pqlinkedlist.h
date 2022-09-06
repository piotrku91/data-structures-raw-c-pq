#ifndef _PQLINKEDLIST_H_
#define _PQLINKEDLIST_H_

#include <stdint.h>
#include <stdbool.h>

/* PqLinkedList - My own implementation of linked list
   Piotr K. (dajmosster@gmail.com)
   piotrq.eu
*/

#ifndef PQLINKEDLISTTYPE
/* Use this macro to define type of elements PqLinkedList - default is uint8_t */
#define PQLINKEDLISTTYPE uint8_t
#endif

typedef struct
{
    struct PqNode *next_node;
    PQLINKEDLISTTYPE data;
} PqNode;

typedef struct
{
    PqNode *head_node;
} PqLinkedList;

/**
 * @brief Initialize PqLinkedList struct with NULL head node
 * 
 * @param pq_linkedlist PqLinkedList struct
 */
void PqLinkedListInit(PqLinkedList *pq_linkedlist);

/**
 * @brief Inserts data element on the begin of PqLinkedList
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @param data Data element
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListInsertFirst(PqLinkedList *pq_linkedlist, PQLINKEDLISTTYPE data);

/**
 * @brief Inserts data element on the end of PqLinkedList
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @param data Data element
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListInsertLast(PqLinkedList *pq_linkedlist, PQLINKEDLISTTYPE data);

/**
 * @brief Inserts data element on specified position
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @param index Position to insert new data element
 * @param data Data element
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListInsertAtIndex(PqLinkedList *pq_linkedlist, uint32_t index, PQLINKEDLISTTYPE data);

/**
 * @brief Delete data element on specified position
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @param index Position to delete data element
 * @param data Data element
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListDeleteByIndex(PqLinkedList *pq_linkedlist, uint32_t index);

/**
 * @brief Delete first element matches the data parameter
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @param data Data element to delete
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListDeleteByDataValue(PqLinkedList *pq_linkedlist, PQLINKEDLISTTYPE data);

/**
 * @brief Clear PqLinkedList
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListClear(PqLinkedList *pq_linkedlist);

/**
 * @brief Gets data from specific position
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @param index Position to read
 * @param data_return Pointer to data for return if found
 * @return true - success,
 * @return false - fail
 */
bool PqLinkedListGetDataByIndex(PqLinkedList *pq_linkedlist, uint32_t index, PQLINKEDLISTTYPE* data_return);

/**
 * @brief Gets current size of PqLinkedList
 * 
 * @param pq_linkedlist PqLinkedList struct
 * @return Size
 */
size_t PqLinkedListGetSize(PqLinkedList *pq_linkedlist);

#endif /* _PQLINKEDLIST_H_ */