#include <stdio.h>

int main(void)
{
        printf("size of int: %lu\n", sizeof(int));
        printf("size of double: %lu\n", sizeof(double));
        printf("size of char: %lu\n", sizeof(char));
        printf("size of char[100]: %lu\n", sizeof(char[100]));
        printf("size of float: %lu\n", sizeof(float));
        printf("size of long int: %lu\n", sizeof(long int));
        printf("size of long double: %lu\n", sizeof(long double));

        return 0;
}