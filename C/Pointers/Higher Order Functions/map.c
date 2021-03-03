#include <stdio.h>

void mapArray(int array[], int arraySize, int (*callback)(int number))
{
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = (*callback)(array[i]);
    }
}

void recursiveMapArray(int array[], int arraySize, int (*callback)(int number))
{
    if (arraySize == 0) return;

    int iterator = arraySize - 1;

    array[iterator] = (*callback)(array[iterator]);

    return recursiveMapArray(array, arraySize - 1, callback);
}

int multiplyBy2(int number)
{
    return number * 2;
}

int main()
{
    int ages[4] = { 10, 20, 19, 18 };

    printf("Before map: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", ages[i]);
    }
    printf("\n");

    // mapArray(ages, 4, multiplyBy2);
    recursiveMapArray(ages, 4, multiplyBy2);

    printf("After map: \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", ages[i]);
    }
    printf("\n");

    return 0;
}