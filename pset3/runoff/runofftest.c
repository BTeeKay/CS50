#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int perferences[2][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    printf("%i\n", perferences[0][1]);
    perferences[0][1] += 1;
    printf("%i\n", perferences[0][1]);


}

for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {

        }
    }

else if (candidates[j].eliminate == true && candidates[j+1].eliminate == false)
            {
                candidates[j+1].votes++
            }

            // set elim candidate place in new array
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].eliminated == true)
            {
                elimCan[j] += j;
                printf("%i\n", elimCan[j]);
            }
        }
    }