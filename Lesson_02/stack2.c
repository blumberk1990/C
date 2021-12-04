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
        printf("%c", *ptr);
    }
    printf("\n");
}

int main() {

    char array[33];
    int len;
    const char pop[3] = "pop";
    const char push[5] = "push";
    
    //Read input
    while (scanf("%s",array) != EOF)
    {
        //change string to lowercase
        toLowercase(array);

        if(strcmp(array, "pop")==0) {
            printf("POP is equal\n");
            }
        else if(strncmp(array, "push", (sizeof("push")/sizeof(char)))==0) {
            printf("PUSH is equal\n");
            }
        else {
             printf("%s, funciotn unknown.\n", array);
        }
        
    }
    

    return 0;
}