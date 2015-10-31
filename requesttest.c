#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>

//Tests the use and implementation of strchr, strcpy, and strstr functions

int main(void)
{
    char* line = "GET /cat.jpg HTTP/1.1\r\n";
    printf("%s\n", line);

    //break the line into its parts
    char* SP1 = strchr(line, ' ');
    char* SP2 = strchr(SP1+1, ' ');
    printf("%d\n", SP1-line);    

    printf("%s\n", SP2);
    int index1 = SP1-line;
    char method[index1];
    printf("length: %d", strlen(method));

    strncpy(method, line, index1);
    
    printf("method: %s\n", method);
    printf("length: %d\n", strlen(method));
}
