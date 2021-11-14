#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int popStart;
    do
    {
        popStart = get_int("Starting Population: ");
    }
    while (popStart < 9);

    // TODO: Prompt for end size
    int popEnd;
    do
    {
        popEnd = get_int("Max Population: ");
    }
    while (popEnd < popStart);

    // TODO: Calculate number of years until we reach threshold
    int yearsTaken = 0;
    int popStartDif;
    int popEndDif;

    while (popStart < popEnd)
    {
        popStartDif = popStart / 3;
        popEndDif = popStart / 4;
        popStart += popStartDif - popEndDif;

        yearsTaken++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", yearsTaken);
}
