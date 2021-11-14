#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//declare prototype
bool checkkey(string stringkey);
//declare variables
int key = 0;


int main(int argc, string argv[])
{
    // uses function check key to make sure key is a digit, sets keytrue
    bool keytrue = checkkey(argv[1]);
    // gives initial output from command line argument and returns 1 if not command line input requested
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (argc == 2 && keytrue == true)
    {
        printf("Success\n");
        //print promt for unencrypted text
        string pt = get_string("plaintext: ");
        string ct = "";
        // apply key and print cipher
        key = atol(argv[1]);
        // ci = (pi + k) % 26
        // going through each character at a time to check it is alphabetical with ctype.h and if it isn't leaving it alone
        // A = ascii 65 a = ascii 97
        printf("ciphertext: ");
        for (int i = 0, n = strlen(pt); i < n; i++)
        {
            char a = pt[i];
            if (isalpha(a))
            {
                if (isupper(a))
                {
                    a -= 65;
                    printf("%c", (a + key) % 26 + 65);
                }
                else
                {
                    a -= 97;
                    printf("%c", (a + key) % 26 + 97);
                }
            }
            else
            {
                printf("%c", a);
            }



        }
        printf("\n");
    }

}

bool checkkey(string stringkey)
{

    return true;
    //check key is a digit
    for (int i = 0, n = strlen(stringkey); i < n; i++)
    {
        if (!isdigit(stringkey[i]))
        {
            return false;
        }
    }
}