#include <stdio.h>
#include <math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{
        int i;
        for (i = -30; i < 30; i++)
        {
                double interval = i / 10.0;
                double absValue = sin(interval);
                if (absValue < 0) absValue = -absValue;
                printf("sin(% lf) = %lf \n", interval, absValue);
        }

        printf("\n++ ++ ++ +\n");
        return 0;
}