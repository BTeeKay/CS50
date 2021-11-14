#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float total = 0;
    int counter = 0;
    int dollars = 0;

    // get users input
    do
    {
        total = get_float("Change owed: ");
    }
    while (total < 0.00);

    //convert users input to whole number
    dollars = round(total * 100);

    // use while loops to take away each value until condition is no longer met, whilst adding 1 to the counter
    // 25 cent while
    while (dollars >= 25)
    {
        dollars = dollars - 25;
        counter++;
    }
    // 10 cent while
    while (dollars >= 10)
    {
        dollars = dollars - 10;
        counter++;
    }
    // 5 cent while
    while (dollars >= 5)
    {
        dollars = dollars - 5;
        counter++;
    }
    // 1 cent while
    while (dollars >= 1)
    {
        dollars = dollars - 1;
        counter++;
    }



    printf("%i\n", counter);
}