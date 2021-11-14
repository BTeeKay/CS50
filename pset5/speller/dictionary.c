// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// global variable for size function
unsigned int counter = 0;

// Number of buckets in hash table (initial 26*26*26 = 17576) = 0.08 seconds
// 26*26*26*26 = 456976 = 0.08 seconds total as well. Hash Function matters more.
const unsigned int N = 17576;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    // hash the word
    unsigned int value = hash(word);
    //create cursor
    node *cursor = table[value];
    if (cursor == NULL)
    {
        return false;
    }

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // this is the hash function from Doug Lloyd's short "Hash Tables"
    // I did have my own hash function as a modified FNV but
    // tolower was editing the pointer to word, so check50 was failing
    // because everything was lowercase.
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += (tolower(word[i]) + 2);
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open file and set variables
    char word[LENGTH + 1];
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }
    // Still not sure if a while loop is the best for this.
    while (fscanf(input, "%s", word) != EOF)
    {
        counter++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;
        // give word a hash value
        int value = hash(word);
        // insert into hash table - first case value empty
        if (table[value] == NULL)
        {
            table[value] = n;
        }
        // if collision then add node to front of linked list in hash table
        else
        {
            n->next = table[value];
            table[value] = n;
        }
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N + 1; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }

    }
    return true;
}
