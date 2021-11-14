#include <stdio.h>
#include <cs50.h>

string checkkey(string x, string a);

int main(void)
{
    string x = "hello";
    string a = "test";
    checkkey(x, a);
}

string checkkey(string x, string a)
{
    printf("%s\n", x);
    printf("%s\n", a);
    x = "change1";
    a = "change2";
    return x;
    return a;
}