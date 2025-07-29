#include <stdio.h>
#include <stdbool.h>

// Asks for a number and then calculates if its prime or not
int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    bool isprime = true;

    if (number <= 1)
    {
        isprime = false;
    }
    else
    {
        for (int i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
                isprime = false;
        }
    }

    if (isprime)
    {
        printf("%d is a prime.\n", number);
    }
    else
    {
        printf("%d is not a prime.\n", number);
    }

    return 0;
}
