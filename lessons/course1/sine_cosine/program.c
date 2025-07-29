#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("  x\t  sin(x)\tcos(x)\n");
    printf("-----------------------------\n");

    for (x = 0.0; x <= 1.0; x += 0.1) {
        printf("%0.1f\t%0.6f\t%0.6f\n", x, sin(x), cos(x));
    }
    return 0;
}
