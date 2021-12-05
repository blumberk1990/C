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

// Validation of entered data,
// return:  '-1' - no valid data; 
// return:  '0' - data valid
// valueString, output array with value in string format
int validatePushFunction(char* string, char* valueString) {
    
    int dataValid = 0;

    // Starting validation after 4 digits (string+4 = "push")
    for(char* ptr= string+4; *ptr; ++ptr) {
        if(*ptr==' ' && ((*(ptr+1)=='-' && isdigit(*(ptr+2))) || isdigit(*(ptr+1)))) {
            dataValid=1;
        } else if(!dataValid) {
            printf("Wrong input format!!, example: push -25\n");
            return -1;
        } else if(dataValid) {
            *valueString = *ptr;
            valueString++;
        }
    }
    *valueString = 0;
    return 0;
}

// Convert string to int
int stringToValue(char* string) {
    int value = 0;
    int factor = 1;
    int sign = 1;
    int length = sizeof(*string)/sizeof(char);
    printf("%d", sizeof(*string)/sizeof(char));
    // length -1, becaouse array ptr is equal to array[0]
    for(char *ptr= string + length-1; *ptr; --ptr) {
        if(*ptr=='-') {
            sign = -1;
        } else if(isdigit(*ptr)) {
            value +=  (*ptr - 0x30)*factor;
            factor*=10;
        }
    }
    return value*sign;
}

int main() {

    char array[ARRAY_LENGHT];
    char stringValue[12];
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
                if(!validatePushFunction(array, stringValue)) {
                    push(&stack, stringToValue(stringValue));
                }      
            }
        else {
             printf("%s, funciotn unknown. Please repeat.\n", array);
        }
        
    }
    

    return 0;
}