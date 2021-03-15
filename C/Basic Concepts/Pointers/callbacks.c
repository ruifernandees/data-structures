#include <stdio.h>

int calculator(int a, int b, int (*operationFunction)(int a, int b))
{
    int result = (*operationFunction)(a, b);
    return result;
}

int sum(int a, int b) 
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int (*sumPointer)(int, int) = sum;
    int (*subPointer)(int, int) = sub;
    int (*multiplyPointer)(int, int) = multiply;

    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d + %d = %d\n", a, b, calculator(a, b, sumPointer));
    printf("%d - %d = %d\n", a, b, calculator(a, b, subPointer));
    printf("%d * %d = %d\n", a, b, calculator(a, b, multiplyPointer));

    return 0;
}