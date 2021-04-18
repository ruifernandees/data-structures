#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct aux {
    TYPEKEY key;
    struct aux *left;
    struct aux *right;
    int height;
} node;

node *createNode(TYPEKEY key)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->key = key;
    newNode->height = 0;

    return newNode;
}

node *initialize()
{
    return NULL;
}

int max(int number1, int number2)
{
    if (number1 > number2)
    {
        return number1;
    }
    return number2;
}

int getHeight(node *root)
{
    if (!root) return -1;

    return root->height;
}

node *rotateRight(node *r)
{
    node *aux;
    aux = r->left;
    r->left = aux->right;
    aux->right = r;

    r->height = max(getHeight(r->right), getHeight(r->left)) + 1;
    aux->height = max(getHeight(aux->left), r->height) + 1;

    return aux;
}

node *rotateLeft(node *r)
{
    node *aux;
    aux = r->right;
    r->right = aux->left;
    aux->left = r;

    r->height = max(getHeight(r->right), getHeight(r->left)) + 1;
    aux->height = max(getHeight(aux->right), r->height) + 1;

    return aux;
}

node *rotateLeftRight(node *r)
{
    r->left = rotateLeft(r->left);
    return rotateRight(r);
}

node *rotateRightLeft(node *r)
{
    r->right = rotateRight(r->right);
    return rotateLeft(r);
}

node *insert(node *root, TYPEKEY key)
{
    if (!root)
    {
        return createNode(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
        if ((getHeight(root->left) - getHeight(root->right)) == 2)
        {
            if (key < root->left->key)
            {
                root = rotateRight(root);
            }
            else
            {
                root = rotateLeftRight(root);
            }
        }
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);

        if ((getHeight(root->right) - getHeight(root->left)) == 2)    
        {
            if (key > root->right->key)
            {
                root = rotateLeft(root);
            }
            else
            {
                root = rotateRightLeft(root);
            }
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    return root;
}