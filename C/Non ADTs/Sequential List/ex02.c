#include <stdio.h>
#include "SequentialList.c"

int main() {
    LIST myList;
    initStructure(&myList);

    REGISTER register1 = { 10 };
    REGISTER register2 = { 15 };
    REGISTER register3 = { 20 };

    insertListElement(&myList, register1, 0);
    insertListElement(&myList, register2, 0);
    insertListElement(&myList, register3, 0);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));

    printf("10 is %d\n", sentinelSearch(&myList, 10));
    printf("15 is %d\n", sentinelSearch(&myList, 15));
    printf("20 is %d\n\n\n", sentinelSearch(&myList, 20));

    removeListElement(&myList, 10);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));

    printf("10 is %d\n", sentinelSearch(&myList, 10));
    printf("20 is %d\n\n\n", sentinelSearch(&myList, 20));

    rebootList(&myList);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));
    
    return 0;
}