#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};
    string name = get_string("Name: ");


    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
