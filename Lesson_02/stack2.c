#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_LENGHT 33

// Structure of the stack object
typedef struct stackEl {
    int value;
    struct stackEl* next;
} stackEl;

// Creating new singel object of the type stackEl 
stackEl newStackEl(int value) {
    stackEl element = {value, NULL};
    return element;
}

// Dynamic allocation of the elment in stack
void push(stackEl** ptr, int value) {
    stackEl* newElement = (stackEl*)malloc(sizeof(stackEl));
    newElement->value = value;
    newElement->next = *ptr;
    *ptr = newElement;
}

// Freeing memory of higher element of stack
int pop(stackEl** ptr) {
    stackEl* oldPtr;
    int value;
    if(*ptr!=NULL) {
        oldPtr = *ptr;
        value = oldPtr->value;
        *ptr = (*ptr)->next;
        free(oldPtr);
    } else {
        printf("Stack is empty, pop function cannot be performed.\n ");
    }
}

// All Aplhanumeric char to lowercase, array of char[]
void toLowercase(char* string) {
    for(char *ptr = string; *ptr; ++ptr) {
        *ptr = *ptr >= 0x41 && *ptr <= 0x5A ? *ptr | 0x60 : *ptr;  
    }
}

// validate date from user, and parse int from string
int parseValueFromString(char* string) {
        int value = 0;
        int factor = 1;
        int dataValid = 0;
        int endValue = 0;
        char sign; 
        char valueHolder[11]; // max digit for signed int == 11
        int i=0;
        //Starting validation after 4 digit
        for(char *ptr= string+4; *ptr; ++ptr) {
            if(dataValid==0) {
                //data validation
                if(*ptr==' ' && ((*(ptr+1)=='-' && isdigit(*(ptr+2))) || isdigit(*(ptr+1)))) {
                    dataValid=1;
                } else{
                    printf("Wrong input format!!, example: push 2\n");
                }
            } else {
                if(endValue==0) {
                    if(isdigit(*ptr) && isdigit(*(ptr+1))) {
                        valueHolder[i] = *ptr;
                        i++;
                    } else if(*ptr!='-') {
                        valueHolder[i] = *ptr;
                        //end String char
                        valueHolder[i+1] = 0;
                        endValue = 1;
                    } else if(*ptr=='-') {
                        sign = '-';
                    }
                }
                
            }
        }
        //i is known from upper function
        //convert String to int
        for(i; i>=0; i--) {
            value += (valueHolder[i] - 0x30)*factor;
            factor*=10;
        }
        //if the value is -, negation of value
        return value = value && sign!= '-' ? value : (~value)+1;
}









int main() {

    char array[ARRAY_LENGHT];
    int len;
    const char popA[4] = "pop";
    const char pushA[5] = "push";
    char* c;
    stackEl* stack = NULL;
    int value;

    //Read input
    //fgets works with buffer, so there is nor problem about geting space char
    while (*(c = fgets(array, ARRAY_LENGHT, stdin)) != EOF)
    {   
        //change string to lowercase
        toLowercase(array);
        //
        if(strncmp(array, popA, (sizeof(popA)/sizeof(char))-1) == 0) {
                pop(&stack);
            }
        else if(strncmp(array, pushA, (sizeof(pushA)/sizeof(char))-1) == 0) {
                push(&stack, parseValueFromString(array));
            }
        else {
             printf("%s, funciotn unknown. Please repeat.\n", array);
        }
        
    }
    

    return 0;
}