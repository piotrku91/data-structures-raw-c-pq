#include <stdio.h>
#include "PqBinaryTree.h"


void display_one_element(uint8_t* data)
{
printf("%d\n", *data);
}


int main(void)
{
    PqBinaryTree pq_binarytree;

    PqBinaryTreeInit(&pq_binarytree);

    PqBinaryTreeInsertNode(&pq_binarytree, 21);
    PqBinaryTreeInsertNode(&pq_binarytree, 88);
    PqBinaryTreeInsertNode(&pq_binarytree, 8);
    //\PqBinaryTreeInsertNode(&pq_binarytree, 200);
    PqBinaryTreeInsertNode(&pq_binarytree, 65);
    PqBinaryTreeInsertNode(&pq_binarytree, 3);
     
    
    PqBinaryTreeInsertNode(&pq_binarytree, 22);
   
    PqBinaryTreeInsertNode(&pq_binarytree, 7);
   
    
    
    printf("PreOrder\n");
    PqBinaryTreeGetDataByCallback(&pq_binarytree, PqBinaryTreePreOrder, display_one_element);
    printf("\nInOrder\n");
    PqBinaryTreeGetDataByCallback(&pq_binarytree, PqBinaryTreeInOrder, display_one_element);
    printf("\nPostOrder\n");
    PqBinaryTreeGetDataByCallback(&pq_binarytree, PqBinaryTreePostOrder, display_one_element);
}