#include <stdio.h>
#include "pqlinkedlist.h"

void display_list(PqLinkedList *list)
{
     for (size_t i = 0; i < PqLinkedListGetSize(list); i++)
    {
        uint8_t data;
        bool success = PqLinkedListGetDataByIndex(list, i, &data);

        if (success)
        {
            printf("%d\n", data);
        }
    }
}

int main(void)
{
    PqLinkedList list;
    PqLinkedListInit(&list);
    PqLinkedListInsertFirst(&list, 95);
    PqLinkedListInsertFirst(&list, 85);
    PqLinkedListInsertFirst(&list, 75);
    PqLinkedListInsertLast(&list, 200);
    PqLinkedListInsertAtIndex(&list, 0, 42);
    PqLinkedListDeleteByIndex(&list, 2);
    PqLinkedListDeleteByDataValue(&list, 200);
    // PqLinkedListClear(&list);

    display_list(&list);
}