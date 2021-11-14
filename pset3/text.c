#include <stdio.h>
#include <cs50.h>
void second(void);


int main(void)
{
    second();
}

void second(void)
{
    string hello = "hello, I can't believe this works in C";
    printf("%s\n", hello);
}