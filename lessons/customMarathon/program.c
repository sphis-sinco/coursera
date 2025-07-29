#include <stdio.h>

int main(void)
{
        int miles = 26, yards = 385;        

        printf("Please enter the miles as an integer:");
        scanf("%d", &miles);       

        printf("Please enter the yards as an integer:");
        scanf("%d", &yards);

        double kilometers;

        kilometers = 1.609 * (miles + yards / 1760.0);
        printf("\nYour marathon is %lf kilometers\n\n", kilometers);

        return 0;
}