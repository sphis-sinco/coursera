#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int main()
{
        // assert(0); // fail
        // assert(1); // succeed
        double x, y;
        while(1)
        {
                printf("Read in 2 floats:\n");
                scanf("%lf %lf", &x, &y);
                assert(y != 0);
                printf("%lf/%lf = %lf\n", x, y, x/y);
        }

        return 0;
}