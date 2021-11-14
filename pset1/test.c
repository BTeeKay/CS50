#include <cs50.h>
#include <stdio.h>

int main()
{
    int s;
    do
    {
        s = get_int("Start size: ");
    }
    while (s < 9);

    int e;
    do
    {
        e = get_int("End Size: ");
    }
    while (s > e);

    int years = 0;

    while (s < e)
    {
        s = s + (s / 3) - (s - 4);
        years++;
    }

    printf("Years: %i", years);

}