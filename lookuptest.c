#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

char* lookup(char* extension);

int main(void)
{
    printf("test extension, please:\n");
    string extension = GetString();
    
    string word = lookup(extension);
    
    if (strcmp(word, "apple/0")==0)
    {
        printf("%s\n", word);
    }
    else if(strcmp(extension, "orange")==0)
    {
        printf("orange!\n");
    }
    else
    {
        printf("give me fruit!\n");
    }
}

char* lookup(char* extension)
{
    if (strcmp(extension, "apple")==0)
    {
        return "apple/0";
    }
    else 
    {
        return "string!";
    }
}
