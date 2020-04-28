// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];
int wordcount = 0;
node *head = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashed = hash(word);
    
    if(table[hashed] == NULL)
    {
        return false;
    }
    
    for(node *cursor = table[hashed]; cursor != NULL; cursor = cursor->next)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        sum += toupper(word[i]);;
    }
    
    return sum % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if(dict == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];
    
    wordcount = 0;
    
    while(fscanf(dict, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        
        memset(new_node, 0, sizeof(node));
        
        if(new_node == NULL)
        {
            unload();
            return false;
        }
        
        wordcount++;
        
        strcpy(new_node->word, word);
        
        
        int hashed = hash(word);
        
        
        if(table[hashed] == NULL)
        {
            table[hashed] = new_node;
            head = new_node;
        }
        else
        {
            new_node->next = table[hashed];
            table[hashed] = new_node;
            head = new_node;
        }
        
    }
    
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            node *cursor = table[i];
            while(cursor != NULL)
            {
                node *tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
        }
    }
    return true;
}
