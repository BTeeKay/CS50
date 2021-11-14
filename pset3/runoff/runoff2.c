#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// define constant upper limits
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// array for voters preferences in election, holding two ints, used as [i][j] later in for loops
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// candidate data type
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

//array of candidates using new data struct
candidate candidates[MAX_CANDIDATES];

// numbers of voters and candidates, global variables.
int voter_count;
int candidate_count;

// function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    //check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        
    }
}