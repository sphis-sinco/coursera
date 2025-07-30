#include <stdio.h>

typedef enum month
{
        january,
        febuary,
        march,
        april,
        may,
        june,
        july,
        august,
        september,
        october,
        november,
        december
} month;
typedef struct date
{
        month m;
        int d
} date;

void print_date(month m, int d)
{
        switch (m)
        {
        case january:
                printf("January");
                break;
        case febuary:
                printf("Febuary");
                break;
        case march:
                printf("March");
                break;
        case april:
                printf("April");
                break;
        case may:
                printf("May");
                break;
        case june:
                printf("June");
                break;
        case july:
                printf("July");
                break;
        case august:
                printf("August");
                break;
        case september:
                printf("September");
                break;
        case october:
                printf("October");
                break;
        case november:
                printf("November");
                break;
        case december:
                printf("December");
                break;

        default:
                printf("%d", m);
        }
        printf(" %lf", d);
}

int main(void)
{
        date thedate = {
            january,
            15};
        print_date(thedate.m, thedate.d);

        return 0;
}