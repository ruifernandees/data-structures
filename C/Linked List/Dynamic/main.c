#include <stdio.h>
#include "DynamicLinkedList.c"

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

    insertListElement(&myList, reg1);
    insertListElement(&myList, reg2);
    insertListElement(&myList, reg3);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    insertListElement(&myList, reg4);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    deleteListElement(&myList, reg4.key);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    
    rebootList(&myList);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    
    

    return 0;
}