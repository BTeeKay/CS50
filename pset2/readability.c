#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //declare prototypes for complier
    int compute_letters();
    int compute_words();
    int compute_sentences();


    //declare the variables we need, also keep them in one place
    float letters = 0.0;
    float words = 0.0;
    float sentences = 0.0;
    float L = 0.0;
    float S = 0.0;
    float I = 0.0;
    //get the text from the user to grade
    string userText = get_string("text: ");
    string GRADE = "";

    // get values from the text
    letters = compute_letters(userText);
    words = compute_words(userText);
    sentences = compute_sentences(userText);

    // use Coleman-Liau index ( index = 0.0588 * L - 0.296 * S - 15.8 )
    // L is the average number of letters per 100 words
    // S is the average number of sentences per 100 words
    L = (letters / words) * 100;
    S = (sentences / words) * 100;
    I = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (I < 1)
    {
        GRADE = "Before Grade 1";

    }
    else if (I == 1)
    {
        GRADE = "Grade 1";

    }
    else if (I == 2)
    {
        GRADE = "Grade 2";

    }
    else if (I == 3)
    {
        GRADE = "Grade 3";

    }
    else if (I == 4)
    {
        GRADE = "Grade 4";

    }
    else if (I == 5)
    {
        GRADE = "Grade 5";

    }
    else if (I == 6)
    {
        GRADE = "Grade 6";

    }
    else if (I == 7)
    {
        GRADE = "Grade 7";

    }
    else if (I == 8)
    {
        GRADE = "Grade 8";

    }
    else if (I == 9)
    {
        GRADE = "Grade 9";

    }
    else if (I == 10)
    {
        GRADE = "Grade 10";

    }
    else if (I == 11)
    {
        GRADE = "Grade 11";

    }
    else if (I == 12)
    {
        GRADE = "Grade 12";

    }
    else if (I == 13)
    {
        GRADE = "Grade 13";

    }
    else if (I == 14)
    {
        GRADE = "Grade 14";

    }
    else if (I == 15)
    {
        GRADE = "Grade 15";

    }
    else if (I == 16)
    {
        GRADE = "Grade 16";

    }
    else
    {
        GRADE = "Grade 16+";

    }


    //print grade

    printf("%s\n", GRADE);

}

int compute_letters(string letter)
{
    int LETTER = 0;

    for (int i = 0, n = strlen(letter); i < n; i++)
    {

        if (isalpha(letter[i]))
        {
            LETTER++;
        }
    }

    return LETTER;
}

int compute_words(string word)
{
    int WORD = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isspace(word[i]))
        {
            WORD++;
        }
    }

    WORD += 1;
    return WORD;
}

int compute_sentences(string senten)
{
    int SENTEN = 0;

    for (int i = 0, n = strlen(senten); i < n; i++)
    {
        if (senten[i] == '.' || senten[i] == '?' || senten[i] == '!')
        {
            SENTEN++;
        }
    }

    return SENTEN;
}

