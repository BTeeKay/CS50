#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{

string argv[] = {"5"};
int argc = 2;
if (argc == 2)
    {
        if (!isdigit(argv[0]))
        {
            printf("Yeah this is a digit\n");
        }
        else
        {
            printf("nah not a digit\n");
        }
    }
}