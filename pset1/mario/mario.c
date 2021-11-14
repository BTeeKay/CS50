#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get a positive int from user that is between 1 and 8
    int h = 0;
    // int for two spaces in middle, probably a better way to do this
    int mid = 1;


    do
    {
        h = get_int("Height: ");
    }
    while (h > 8 || h < 1);

    // print users Height input as a pyramid

    for (int i = 0; i < h; i++)
    {
        // using the rule that the amount of spaces is height - 1
        // also used an extra minus 1 in rule as printed a space on line 0
        for (int x = 0; x < h - i - 1; x++)
        {
            printf(" ");
        }
        //useing the rule that the amount of hashes is line + 1
        for (int y = 0; y < i + 1; y++)
        {
            printf("#");
        }

        for (int z = 0; z < mid; z++)
        {
            printf(" ");
        }

        for (int aa = 0; aa < i + 1; aa++)
        {
            printf("#");
        }

        printf("\n");
    }

}