#include <stdio.h>

#define POEM "Tis so much joy! ‘Tis so much joy!\nIf I should fail, what poverty!\nAnd yet, as poor as I,\nHave ventured all upon a throw!\nHave gained! Yes! Hesitated so—\nThis side the Victory!\n\nLife is but Life! And Death, but Death!\nBliss is, but Bliss, and Breath but Breath!\nAnd if indeed I fail,\nAt least, to know the worst, is sweet!\nDefeat means nothing but Defeat,\nNo drearier, can befall!\n\nAnd if I gain! Oh Gun at Sea!\nOh Bells, that in the Steeples be!\nAt first, repeat it slow!\nFor Heaven is a different thing,\nConjectured, and waked sudden in—\nAnd might extinguish me!"

int main(void)
{

        printf(POEM);
        printf("\n\nDid you like the poem?\n");
        
        char answer[1];       

        printf("Please enter your answer as a single character (Y/N prefered):\n> "); 
        scanf("%s", &answer);   

        printf("%s", answer);

        if (answer == "y" || answer == "Y")
        {
                printf("? Yay!");
        } else if (answer == "n" || answer == "N")
        {
                printf("? Oh...");
        } else {
                printf("... Huh?");
        }

        return 0;
}