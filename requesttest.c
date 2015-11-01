#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

//Tests the use and implementation of strchr, strcpy, and strstr functions

int main(void)
{
    char* line = "GET /cat.jpg HTTP/1.1\r\n";
    printf("line: %s\n", line);
        
    //right after method, before request: [3] 
    char* SP1 = strchr(line, ' ');
        
    //after request, before HTTP [12]
    char* SP2 = strchr(SP1+1, ' ');
    
    //after HTTP, start of CRLF [21]
    char* CRLF = strstr(line, "\r\n");
    
    //calculate length of sub-strings
    int methodsize = SP1-line; 
    int targetsize = SP2-SP1-1; 
    int httpsize = CRLF-SP2-1; 
     
    //store sub-strings
    char* method = malloc(sizeof(char)*methodsize+1);
    char* target = malloc(sizeof(char)*targetsize+1);
    char* http = malloc(sizeof(char)*httpsize+1);

    //copy sub-strings to storage
    strncpy(method, line, methodsize);
    strncpy(target, SP1+1, 8);
    strncpy(http, SP2+1, httpsize);
    
    printf("method: %s\n", method);
    printf("target: %s\n", target);
    printf("http: %s\n", http);
    
    if (strchr(target, ' ') != NULL)
    {
        printf("error 400: too many spaces\n");
    }
    
    char* GET = "GET";
    if (strcmp(method, GET) != 0)
    {
        printf("405: method is incorrect.\n");
    }
    
    char* ext = strchr(target, '.');
    char* query = strchr(target, '?');
    if (query != NULL && query < ext)
    {
        printf("error 400: incorrect ? in target.\n");
    }
    
    free(method);
    free(target);
    free(http);
}

