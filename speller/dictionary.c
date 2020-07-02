// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <stdio.h>
#include <strings.h>



#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int totalwords = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];
    
    if (strcasecmp(cursor->word, word) == 0)
    {
        return true;
    }
    //traverse linked list until word is found
    while(cursor -> next != NULL)
    {
        cursor = cursor->next;
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
            
        }
        
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //one bucket for each letter of the alphabet
    int n = (int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open the dictionary and allocate the space needed for a word
    FILE *file = fopen(dictionary, "r");
    char *dictword = malloc(LENGTH);
    if(dictword == NULL)
    {
        return false;
    }
    // keep scanning the file until the End Of File
    while (fscanf(file, "%s", dictword) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n==NULL)
        {
            return false;
        }
        //copys word and update word count
        strcpy(n->word, dictword);
        totalwords++;
        
        n->next = table[hash(dictword)];
        
        table[hash(dictword)] = n;
        
    }
    
    fclose(file);
    free(dictword);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //create to variables to traverse the loop, one to keep track of the head of linked list, one to increment 
    node *temp;
    node *cursor;
    
    //increment for every letter of the array
    
    for(int i = 0; i < N; i++)
    {
        if(table[i] == NULL)
        {
            continue;
        }    
        
        cursor = table[i];
        temp =cursor;
        
        //keep freeing memory until you reach the end of the loop
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        
        free(cursor);
    }
    
    return true;
}
