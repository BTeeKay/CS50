#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int a = 3;
    int b = 8;
    int c = 9;
    int d = 10;

    a = round(a/2);
    b = round(b/2);

    printf("%i\n", a);
    printf("%i\n", b);
}