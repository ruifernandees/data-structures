#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main()
{
    node *myTree = initialize();

    myTree = createNewNode(15);

    node *newNode;

    newNode = createNewNode(8);
    insert(myTree, newNode);

    newNode = createNewNode(23);
    insert(myTree, newNode);

    newNode = createNewNode(2);
    insert(myTree, newNode);

    newNode = createNewNode(12);
    insert(myTree, newNode);

    newNode = createNewNode(20);
    insert(myTree, newNode);

    newNode = createNewNode(30);
    insert(myTree, newNode);
    
    newNode = createNewNode(40);
    insert(myTree, newNode);

    showTree(myTree);
    printf("\n");

    removeNode(myTree, 40);
    showTree(myTree);
    printf("\n");

    removeNode(myTree, 8);
    showTree(myTree);
    printf("\n");

    return 0;
}