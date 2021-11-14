#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int x[] = {2, 3, 6, 8, 9, 11};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (x[i] > x[j])
            printf("i is bigger");
            else
            printf("who knows what I am doning");

        }

        printf("this is i: %i\n", i);
    }
}