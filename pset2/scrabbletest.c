#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


int main(void)
{

    int total = 0;
    int x = 0;

    string word = get_string("type in here dummy: ");

    for (int i = 0, n = strlen(word); i < n; i++)
    {
       word[i] = toupper(word[i]);
    }
    printf("%i\n", word[0]);

    for (int j = 0, m = strlen(word); j < m; j++)
    {
        word[j] -= 65;
        x = (int) word[j];
        total += POINTS[x];
    }


    printf("%i\n", total);
}
