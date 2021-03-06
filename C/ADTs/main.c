#include <stdio.h>
#include "fraction.h"

int main()
{
    fraction *f1, *f2;

    f1 = createFraction(1, 2);
    f2 = createFraction(3, 4);

    fraction *f3 = sum(f1, f2);

    printFraction(f1);
    printFraction(f2);
    printFraction(f3);

    destroyFraction(f1);
    destroyFraction(f2);
    destroyFraction(f3);

    return 0;
}