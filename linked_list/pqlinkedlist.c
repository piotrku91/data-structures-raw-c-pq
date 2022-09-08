#include "pqlinkedlist.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PqLinkedListInit(PqLinkedList *pq_linkedlist)
{
    pq_linkedlist->head_node = NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListIsEmpty(PqLinkedList *pq_linkedlist)
{
    return pq_linkedlist->head_node == NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListInsertFirst(PqLinkedList *pq_linkedlist, PQLINKEDLISTTYPE data)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        PqNode *new_node = malloc(sizeof(PqNode));
        if (new_node)
        {
            pq_linkedlist->head_node = new_node;
            new_node->data = data;
            new_node->next_node = NULL;
            return true;
        }
    }

    PqNode *new_node = malloc(sizeof(PqNode));
    if (new_node)
    {
        PqNode *old_head_node = pq_linkedlist->head_node;
        pq_linkedlist->head_node = new_node;
        new_node->data = data;
        new_node->next_node = (struct PqNode *)old_head_node;
        return true;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListInsertLast(PqLinkedList *pq_linkedlist, PQLINKEDLISTTYPE data)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        PqNode *new_node = malloc(sizeof(PqNode));
        if (new_node)
        {
            pq_linkedlist->head_node = new_node;
            new_node->data = data;
            new_node->next_node = NULL;
            return true;
        }
    }

    PqNode *current_node = pq_linkedlist->head_node;
    while (current_node != NULL)
    {
        if (current_node->next_node == NULL)
        {
            PqNode *new_node = malloc(sizeof(PqNode));
            if (new_node)
            {
                new_node->data = data;
                new_node->next_node = NULL;

                current_node->next_node = (struct PqNode *)new_node;
                return true;
            }

            return true;
        }
        current_node = (PqNode *)current_node->next_node;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListInsertAtIndex(PqLinkedList *pq_linkedlist, uint32_t index, PQLINKEDLISTTYPE data)
{
    if (index == 0 || PqLinkedListIsEmpty(pq_linkedlist))
    {
        return PqLinkedListInsertFirst(pq_linkedlist, data);
    };

    PqNode *current_node = pq_linkedlist->head_node;
    PqNode *last_node = NULL;
    uint32_t counter = 0;
    while (current_node != NULL)
    {
        if (counter == index)
        {
            PqNode *new_node = malloc(sizeof(PqNode));
            if (new_node)
            {
                new_node->data = data;
                new_node->next_node = (struct PqNode *)current_node;
                last_node->next_node = (struct PqNode *)new_node;
                return true;
            }
        }

        if (current_node->next_node == NULL)
        {
            return PqLinkedListInsertLast(pq_linkedlist, data);
        }
        last_node = current_node;
        current_node = (PqNode *)current_node->next_node;
        counter++;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListDeleteByIndex(PqLinkedList *pq_linkedlist, uint32_t index)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        return false;
    };

    if (index == 0)
    {
        PqNode *new_head_node = (PqNode *)pq_linkedlist->head_node->next_node;
        free(pq_linkedlist->head_node);
        pq_linkedlist->head_node = new_head_node;
        return true;
    }

    PqNode *current_node = pq_linkedlist->head_node;
    PqNode *last_node = pq_linkedlist->head_node;
    uint32_t counter = 0;
    while (current_node != NULL)
    {
        if (counter == index)
        {
            last_node->next_node = current_node->next_node;
            free(current_node);
            return true;
        }
        last_node = current_node;
        current_node = (PqNode *)current_node->next_node;
        counter++;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListDeleteByDataValue(PqLinkedList *pq_linkedlist, PQLINKEDLISTTYPE data)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        return false;
    };

    if (pq_linkedlist->head_node->data == data)
    {
        PqNode *new_head_node = (PqNode *)pq_linkedlist->head_node->next_node;
        free(pq_linkedlist->head_node);
        pq_linkedlist->head_node = new_head_node;
        return true;
    }

    PqNode *current_node = pq_linkedlist->head_node;
    PqNode *last_node = pq_linkedlist->head_node;
    while (current_node != NULL)
    {
        if (current_node->data == data)
        {
            last_node->next_node = current_node->next_node;
            free(current_node);
            return true;
        }
        last_node = current_node;
        current_node = (PqNode *)current_node->next_node;
    }
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListClear(PqLinkedList *pq_linkedlist)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        return false;
    };

    PqNode *current_node = pq_linkedlist->head_node;
    while (current_node != NULL)
    {
        PqNode *node_to_delete = current_node;
        current_node = (PqNode *)current_node->next_node;
        free(node_to_delete);
    }

    pq_linkedlist->head_node = NULL;

    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool PqLinkedListGetDataByIndex(PqLinkedList *pq_linkedlist, uint32_t index, PQLINKEDLISTTYPE *data_return)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        data_return = NULL;
        return false;
    }

    PqNode *current_node = pq_linkedlist->head_node;
    uint32_t counter = 0;
    while (current_node != NULL)
    {
        if (counter == index)
        {
            *data_return = current_node->data;
            return true;
        }
        current_node = (PqNode *)current_node->next_node;
        counter++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PqLinkedListTraverseWithCallback(PqLinkedList *pq_linkedlist, void (*callback_function)(PQLINKEDLISTTYPE *data_return))
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        return;
    }

    PqNode *current_node = pq_linkedlist->head_node;
    while (current_node != NULL)
    {
        if (callback_function)
        {
            callback_function(&current_node->data);
        };
        current_node = (PqNode *)current_node->next_node;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
uint32_t PqLinkedListGetSize(PqLinkedList *pq_linkedlist)
{
    if (PqLinkedListIsEmpty(pq_linkedlist))
    {
        return 0;
    }

    PqNode *current_node = pq_linkedlist->head_node;
    uint32_t counter = 0;
    while (current_node != NULL)
    {
        current_node = (PqNode *)current_node->next_node;
        counter++;
    }
    return counter;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////