typedef struct {
    int numerator;
    int denominator;
} fraction;

fraction *createFraction(int numerator, int denominator);

void printFraction(fraction *myFraction);

void destroyFraction(fraction *myFraction);

fraction *sum(fraction *fraction1, fraction *fraction2);