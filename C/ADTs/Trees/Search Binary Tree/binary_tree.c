#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct node_s {
    TYPEKEY key;
    struct node_s *left, *right;
};

node *initialize()
{
    return NULL;
}

node *createNewNode(TYPEKEY key)
{
    node *newNode = (node *) malloc(sizeof(node));
        
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insert(node *root, node *newNode)
{
    if (root == NULL)
    {
        return newNode;
    }

    if (newNode->key < root->key)
    {
        root->left = insert(root->left, newNode);
    }
    else
    {
        root->right = insert(root->right, newNode);
    }

    return root;
}

node *search(TYPEKEY key, node *root)
{
    if (root == NULL) return NULL;

    if (root->key == key)
    {
        return root;
    }

    if (root->key > key)
    {
        return search(key, root->left);
    }

    return search(key, root->right);
}

int getSize(node *root)
{
    if (!root) return 0;

    return getSize(root->left) 
        + 1 
        + getSize(root->right);
}

void showTree(node *root)
{
    if (root == NULL) return;

    printf("%d", root->key);
    printf("(");
    showTree(root->left);
    showTree(root->right);
    printf(")");
}

node *searchNode(node *root, TYPEKEY key, node **parent)
{
    node *current = root;
    *parent = NULL;
    while (current)
    {
        if (current->key == key)
        {
            return current;
        }

        *parent = current;

        if (key < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return NULL;
}

node *removeNode(node *root, TYPEKEY key)
{
    node *parent, *myNode, *p, *q;
    myNode = searchNode(root, key, &parent);

    if (myNode == NULL)
    {
        return root;
    }

    if (!myNode->left || !myNode->right)
    {
        if (!myNode->left)
        {
            q = myNode->right;
        }
        else
        {
            q = myNode->left;
        }
    }
    else
    {
       p = myNode;
       q = myNode->left;

       while (q->right) 
       {
           p = q;
           q = q->right;
       }

       if (p != myNode)
       {
           p->right = q->left;
           q->left = myNode->left;
       }
       q->right = myNode->right;
    }

    int isRoot = !parent;

    if (isRoot)
    {
        free(myNode);
        return q;
    }

    if (key < parent->key)
    {
        parent->left = q;
    }
    else
    {
        parent->right = q;
    }

    free(myNode);
    return root;
}















