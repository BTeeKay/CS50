#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char *word);
#define LENGTH 45

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 143091;
node *table[N];

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Needs two arguments \n");
        return 1;
    }

    long counter = 0;
    int collisions = 0;
    char word[LENGTH + 1];
    FILE *input = fopen(argv[1], "r");
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
        // tolower(word);  not sure wether to lowercase all words now or later
        strcpy(n->word, word);
        n->next = NULL;
        // give word a hash value
        int value = hash(word);
        // insert into hash table - first case value empty
        if (table[value] == NULL)
        {
            table[value] = n;
        }
        //if collision then add node to front of linked list in hash table
        else
        {
            n->next = table[value];
            table[value] = n;
            collisions++;
        }
    }

    printf("%li\n%i\n", counter, collisions);

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
        node *tmp = table[i]->next;
        free(table[i]);
        table[i] = tmp;
        }
        else
        {
            continue;
        }
    }
}

unsigned int hash(const char *word)
{
  unsigned char* p = (unsigned char *) word;
  unsigned long int h = 2166136261UL;
  unsigned long int i;

  for(i = 0; i < strlen(word); i++)
  {
    h = (h * 16777619) ^ p[i] ;
  }

    return h % N;
}

    char *hashword = (char *)word;
    //changing all dictonary words to lowercase
    for (int i = 0; i < strlen(hashword); i++)
    {
        if (hashword[i] == '\'')
        {
            hashword[i] = hashword[i];
        }
        hashword[i] = tolower(hashword[i]);
    }


    unsigned char* p = (unsigned char *) hashword;
    unsigned long int h = 2166136261UL;
    unsigned long int i;

    for(i = 0; i < strlen(hashword); i++)
    {
        h = (h * 16777619) ^ p[i] ;
    }

    return h % N;
}

 int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }

    return sum % N;