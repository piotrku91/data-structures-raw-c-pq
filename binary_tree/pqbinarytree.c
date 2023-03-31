#include "PqBinaryTree.h"
#include <malloc.h>


void PqBinaryTreeInit(PqBinaryTree* pq_binarytree)
{
    pq_binarytree->root = NULL;
}

static void insertNode(PqBinaryTreeNode** tree_ptr, PQBINARYTREEDATATYPE data)
{
    if (!(*tree_ptr)) {
        /* Binary tree is empty */
        (*tree_ptr) = malloc(sizeof(PqBinaryTreeNode));

        if ((*tree_ptr)) {
            (*tree_ptr)->data = data;
            (*tree_ptr)->left_node = NULL;
            (*tree_ptr)->right_node = NULL;
        }
        else
        {
            // No memory available
        }
    }
    else
    {
        /* Binary tree is not empty */
        if (data < (*tree_ptr)->data)
        {
            insertNode(((PqBinaryTreeNode**)&(*tree_ptr)->left_node), data);
        }
        else if (data > (*tree_ptr)->data)
        {
            insertNode(((PqBinaryTreeNode**)&(*tree_ptr)->right_node), data);
        }
        else
        {
            // Data duplication case  
        }
    }
}

static void preOrder(PqBinaryTreeNode* tree_ptr, void(*callback_function)(PQBINARYTREEDATATYPE* data_return))
{
    if (tree_ptr)
    {
        callback_function(&tree_ptr->data);
        preOrder((PqBinaryTreeNode*)tree_ptr->left_node, callback_function);
        preOrder((PqBinaryTreeNode*)tree_ptr->right_node, callback_function);
    }
}

static void inOrder(PqBinaryTreeNode* tree_ptr, void(*callback_function)(PQBINARYTREEDATATYPE* data_return))
{
    if (tree_ptr)
    {
        inOrder((PqBinaryTreeNode*)tree_ptr->left_node, callback_function);
        callback_function(&tree_ptr->data);
        inOrder((PqBinaryTreeNode*)tree_ptr->right_node, callback_function);
    }
}

static void postOrder(PqBinaryTreeNode* tree_ptr, void(*callback_function)(PQBINARYTREEDATATYPE* data_return))
{
    if (tree_ptr)
    {
        postOrder((PqBinaryTreeNode*)tree_ptr->left_node, callback_function);
        postOrder((PqBinaryTreeNode*)tree_ptr->right_node, callback_function);
        callback_function(&tree_ptr->data);
    }
}

void PqBinaryTreeInsertNode(PqBinaryTree* pq_binarytree, PQBINARYTREEDATATYPE data)
{
    insertNode(&pq_binarytree->root, data);
}

void PqBinaryTreeGetDataByCallback(PqBinaryTree* pq_binarytree, PqBinaryTreeOrderType target_order, void(*callback_function)(PQBINARYTREEDATATYPE* data_return))
{
    switch (target_order)
    {
    case PqBinaryTreePreOrder:
    {
        preOrder(pq_binarytree->root, callback_function);
        break;
    }
    case PqBinaryTreeInOrder:
    {
        inOrder(pq_binarytree->root, callback_function);
        break;
    }
    case PqBinaryTreePostOrder:
    {
        postOrder(pq_binarytree->root, callback_function);
        break;
    }
    default:
    {
        break;
    }
    }
}