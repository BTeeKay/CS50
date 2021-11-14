#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long answer = 0.0;


    do
    {
        answer = get_long("Enter number: ");
    }
    while (answer < 1);

    answer = answer % 100;
    printf("%lo\n", answer);

}