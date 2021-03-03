#include <stdio.h>
#include "LinkedList.c"

int main()
{
    LIST myList;

    initList(&myList);

    printf("List initialized!\n");
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    REGISTER reg1 = { 5 };
    REGISTER reg2 = { 9 };
    REGISTER reg3 = { 7 };
    REGISTER reg4 = { 8 };

    insertOrderedListElement(&myList, reg1);
    insertOrderedListElement(&myList, reg2);
    insertOrderedListElement(&myList, reg3);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    insertOrderedListElement(&myList, reg4);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    deleteListElement(&myList, reg4.key);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    printf("\n");

    
    listReboot(&myList);
    printf("List size: %d\n", getListSize(&myList));

    showList(&myList);
    
    

    return 0;
}