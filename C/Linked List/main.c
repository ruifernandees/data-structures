#include <stdio.h>
#include "LinkedList.c"

int main()
{
    LIST myList;

    initLinkedList(&myList);

    printf("List initialized!\n");
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    REGISTER reg1 = { 5 };
    REGISTER reg2 = { 9 };
    REGISTER reg3 = { 7 };
    REGISTER reg4 = { 8 };

    insertElementLinkedList(&myList, reg1);
    insertElementLinkedList(&myList, reg2);
    insertElementLinkedList(&myList, reg3);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    insertElementLinkedList(&myList, reg4);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    deleteListElement(&myList, reg4.key);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    
    rebootLinkedList(&myList);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    
    

    return 0;
}