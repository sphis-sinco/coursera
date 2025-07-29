#include <stdio.h>
int main(void)
{
        int farenheit, celsius;

        printf("Please enter fahrenheit as an integer:");
        scanf("%d", &farenheit);
        celsius = (farenheit - 32)/1.8; // note conversion
        printf("\n %d fahrenheit is %d celsius.\n", farenheit, celsius);

        return 0;
}