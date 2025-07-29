#include <stdio.h>

long fib(int n)
{
        long f2 = 0, f1 = 1, f_old;
        int i;

        for (i = 0; i < n; i++)
        {
                f_old = f2;
                f2 = f2 + f1;
                f1 = f_old;
        };

        return f2;
}

long recursive_fib(int n)
{
        if (n <= 1)
                return n;
        else
                return (recursive_fib(n - 1) + recursive_fib(n - 2));
}

int main(void)
{
        int how_many = 0, i;
        printf("I want a fib table up to ");
        scanf("%d", &how_many);

        printf("\nx\ty\tz\n");
        for (i = 0; i < how_many; i++)
                printf("\n%d\t%ld\t%ld\n", i, fib(i), recursive_fib(i));

        return 0;
}