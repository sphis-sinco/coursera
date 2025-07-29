#include <stdio.h>

int main(void)
{
        int outside, weather;
        printf("Are you outside? (1 true, 0 false)\n");
        scanf("%d", &outside);
        printf("Is it raining? (1 true, 0 false)\n");
        scanf("%d", &weather);

        if (outside && weather)
                printf("\nYou should propably have an umbrella.\n");
        else
                printf("\nNo umbrella needed.\n");

        return 0;
}