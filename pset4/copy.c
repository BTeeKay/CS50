#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
void sausage(void);
int main(void)
{
    char *s = get_string("s: ");

    char *t = s;

    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);
    sausage();
}

void sausage(void)
{
    long a = 2004534563456;
    long b = 30034563456345634;
    long c = 4003456345634;
    long d = 12312341234;
    long e = 31231245345345344;
    long f;

    f = a * b * c * d * e;
    printf("Answer: %lo\n", f);
}