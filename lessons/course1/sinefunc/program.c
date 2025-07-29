#include <stdio.h>
#include <math.h>

int main() {
    float value;

    printf("Enter a value for the value inbetween 0 and 1: ");
    scanf("%f", &value);

    if (value > 0.0 && value < 1.0) {
        float result = sin(value);
        printf("sin(%f) = %f\n", value, result);

        return 0;
    }

    printf("It has to be IN-BETWEEN 0 and 1 goofball.");

    return 0;
}
