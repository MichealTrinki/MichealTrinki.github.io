// Implements a dictionary's functionality

#include <ctype.h>
#include <strings.h>
#include <stdbool.h>
#include  <string.h>
#include "dictionary.h"
#include <stdlib.h>
#include  <stdio.h>
#include   <cs50.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
/// declare all words as int datatype
int all_words = 0;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    ///hash word to obtain hash value - from walkthrough
    int index = hash(word);
    ///Acess linked list at that index in the has table- from walkthrough
    node *cursor = table[index];
   while(cursor != NULL)
   {    if(strcasecmp(cursor->word, word) == 0)
   {
       return true;
   }
       cursor = cursor->next;
   }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
///// hash function
/////reference for this hash is https://www.youtube.com/watch?v=sz5X0Duxy4G&t=75s1
{
    int sum = 0;

    for(int i = 0; i < strlen(word); i++)
      {
          sum+= tolower(word[i]);
      }
      return (sum % N);

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
     ///open dictionary using fopen from walkthrough

      FILE *file = fopen(dictionary, "r'");
      /// file cant be opened
      if(file == NULL)
      {
          return false;
      }
      /// walkthrough next step is read string from file one at a time
      ///fscanf from walkthrough
      //// the max length for char array is defined as length which 45
      char word[LENGTH + 1];

     while (fscanf(file, "%s", word) != EOF)
    {
      ////make new nodes
      //// use malloc to allocate memmory for new nodes
      node *new_node = malloc(sizeof(node));
 //// case for node being null
      if (new_node == NULL)
      {
          return false;
      }
    /// use strcopy function as shown in walkthrough
    strcpy(new_node->word, word);
    new_node->next = NULL;

    ///next walkthrough step
    /////hash word to obtain a hash value

    int index = hash(word);
    /// final load step insert node into hash table at that location
    /// case for a new node based on its place being null
    if(table[index] == NULL)
    {
        table[index] = new_node;
    }
    else
    {
        new_node->next = table[index];
        table[index] = new_node;
    }
    //// increment in the all words function i declared at the top
    all_words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return all_words; /// already explained this further up
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {



    node *head = table[i];
    node *cursor = head;
    node *tmp = head;
    while(cursor != NULL)
    {
        cursor = cursor->next;
        free(tmp);
        tmp = cursor;
    }
     }   // TODO
    return true;
}
