#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

fraction *createFraction(int numerator, int denominator)
{
    if (denominator == 0) 
    {
        return NULL;
    }

    fraction *f = (fraction *) malloc(sizeof(fraction));

    if (f == NULL)
    {
        return NULL;
    }

    f->numerator = numerator;
    f->denominator = denominator;

    return f;
}

void printFraction(fraction *f)
{
    if (f != NULL)
    {
        printf("%d / %d\n", f->numerator, f->denominator);
    }
}

void destroyFraction(fraction *myFraction)
{
    if (myFraction != NULL)
    {
        free(myFraction);
        myFraction = NULL;
    }
}

int mdc(int a, int b)
{
    if (b == 0) return a;

    return mdc(b, a % b);
}

int mmc(int a, int b)
{
    return a * b / mdc(a, b);
}

fraction *sum(fraction *fraction1, fraction *fraction2)
{
    if (fraction1 == NULL || fraction1 == NULL)
    {
        return NULL;
    }

    fraction *result = (fraction *) malloc(sizeof(fraction));

    if (result == NULL) return NULL;

    result->denominator = mmc(fraction1->denominator, fraction2->denominator);
    result->numerator = 
        ((result->denominator / fraction1->denominator) * fraction1->numerator)
        + ((result->denominator / fraction2->denominator) * fraction2->numerator);

    return result;
}