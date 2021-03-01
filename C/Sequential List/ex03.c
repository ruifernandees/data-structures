#include <stdio.h>
#include "SequentialListWithBinarySearch.c"

int main() {
    LIST myList;
    initStructure(&myList);

    REGISTER register1 = { 100 };
    REGISTER register2 = { 15 };
    REGISTER register3 = { 90 };

    insertOrderedListElement(&myList, register1);
    insertOrderedListElement(&myList, register2);
    insertOrderedListElement(&myList, register3);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));

    printf("%d is %d\n", register1.key, binarySearch(&myList, register1.key));
    printf("%d is %d\n", register2.key, binarySearch(&myList, register2.key));
    printf("%d is %d\n\n\n", register3.key, binarySearch(&myList, register3.key));

    removeListElement(&myList, register1.key);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));

    printf("%d is %d\n", register2.key, binarySearch(&myList, register2.key));
    printf("%d is %d\n\n\n", register3.key, binarySearch(&myList, register3.key));

    rebootList(&myList);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));
    
    return 0;
}