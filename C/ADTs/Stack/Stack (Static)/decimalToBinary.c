#include <stdio.h>
#include "stack.h"

int main()
{
    int number;
    printf("Type a number: ");
    scanf("%d", &number);

    
    tStack *binaries;

    binaries = createStack();

    int currentNumber = number;

    while (currentNumber > 0)
    {
        int quotient = currentNumber / 2;
        int rest = currentNumber % 2;

        push(binaries, rest);

        currentNumber = quotient;
    }

    printf("%d in binary is: ", number);
    while (!isEmpty(binaries))
    {
        int currentBit;
        pop(binaries, &currentBit);
        printf("%d", currentBit);
    }
    printf("\n"); 

    destroy(binaries);

    return 0;
}