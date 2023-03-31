#ifndef _PQ_BINARYTREE_
#define _PQ_BINARYTREE_
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* PqBinaryTree 
   Piotr K. (dajmosster@gmail.com)
   piotrq.eu
*/

/* Use this macro to define type of elements PqBinaryTree - default is uint8_t */
#ifndef PQBINARYTREEDATATYPE 
#define PQBINARYTREEDATATYPE uint8_t
#endif

typedef struct
{
   PQBINARYTREEDATATYPE data;
   struct PqBinaryTreeNode *left_node;
   struct PqBinaryTreeNode *right_node;
} PqBinaryTreeNode;

typedef struct
{
   PqBinaryTreeNode *root;
} PqBinaryTree;

typedef enum
{
   PqBinaryTreePreOrder,
   PqBinaryTreeInOrder,
   PqBinaryTreePostOrder
} PqBinaryTreeOrderType;


void PqBinaryTreeInit(PqBinaryTree* pq_binarytree);

void PqBinaryTreeInsertNode(PqBinaryTree* pq_binarytree, PQBINARYTREEDATATYPE data);

void PqBinaryTreeGetDataByCallback(PqBinaryTree* pq_binarytree, PqBinaryTreeOrderType target_order, void(*callback_function)(PQBINARYTREEDATATYPE* data_return));

#endif /* _PQ_BINARYTREE_ */