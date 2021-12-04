#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//Function is working with array of CHAR[], 
//All Aplhanumeric char to lowercase
//
void toLowercase(char* string) {
    for(char *ptr= string; *ptr; ++ptr) {
        *ptr = *ptr >= 0x41 && *ptr <= 0x5A ? *ptr | 0x60 : *ptr;  
    }
}


#define ARRAY_LENGHT 33

int main() {

    char array[ARRAY_LENGHT];
    int len;
    const char pop[4] = "pop";
    const char push[5] = "push";
    char* c;

    //Read input
    //fgets works with buffer, so there is nor problem about geting space char
    while (*(c = fgets(array, ARRAY_LENGHT, stdin)) != EOF)
    {   
        //change string to lowercase
        toLowercase(array);
        //
        if(strncmp(array, pop, (sizeof(pop)/sizeof(char))-1) == 0) {
            printf("POP is equal\n");
            }
        else if(strncmp(array, push, (sizeof(push)/sizeof(char))-1) == 0) {
            printf("PUSH is equal\n");
            }
        else {
             printf("%s, funciotn unknown.\n", array);
        }
        
    }
    

    return 0;
}