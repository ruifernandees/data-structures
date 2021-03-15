#include <stdio.h>
#include <stdlib.h>

typedef int bool;

int* filterArray(int array[], int *arraySizeP, bool (*callback)(int number))
{
    int arraySize = *arraySizeP;
    int validItemsQuantity = 0;
    int validItems[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        bool isValidItem = (*callback)(array[i]);
        if (isValidItem)
        {
            validItems[validItemsQuantity] = array[i];
            validItemsQuantity++;
        }
    }

    int *newArray = (int *) calloc(validItemsQuantity, sizeof(int));

    for (int i = 0; i < validItemsQuantity; i++)
    {
        newArray[i] = validItems[i];
    }

    *arraySizeP = validItemsQuantity;

    return newArray;
}

bool isPositive(int number)
{
    return (number > 0);
}

int main()
{
    int arr[4] = {-1, -20, 5, 10};
    int arraySize = 4;

    int* newArr = filterArray(arr, &arraySize, isPositive);

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d\t", newArr[i]);
    }
    printf("\n");
    
    return 0;
}