#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LENGHT 33

// Structure of the stack object
typedef struct fifoEl {
    int value;
    struct fifoEl* next;
} fifoEl;

// Creating new singel object of the type stackEl 
fifoEl newFifoEl(int value) {
    fifoEl element = {value, NULL};
    return element;
}

// Dynamic allocation of the elment in FIFO
void enque(fifoEl** ptrHead, fifoEl** ptrTail, int value) {
    fifoEl* newElement = (fifoEl*)malloc(sizeof(fifoEl));
    newElement->value = value;
    newElement->next = NULL;
    if(*ptrHead==NULL) {
        *ptrHead = newElement;
    } else {
        (*ptrTail)->next = newElement;
    }
    *ptrTail = newElement;
}

// Freeing memory of first element of FIFO
void deque(fifoEl** ptrHead, fifoEl** ptrTail) {
    fifoEl* oldHead = *ptrHead;
    int value;
    if(*ptrHead==NULL) {
        printf("error\n");
    } else if((*ptrHead) == (*ptrTail)) {
        (*ptrHead)->next = NULL;
        *ptrTail = NULL;
    }
    *ptrHead = (*ptrHead)->next;
    value = oldHead->value;
    free(oldHead);
    printf("%d\n", value);
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
int validateEnqueFunction(char* string, char* valueString) {
    int dataValid = 0;
    // Starting validation after 5 digits (string+5 = "enque")
    for(char* ptr= string+5; *ptr; ++ptr) {
        if(*ptr==' ' && ((*(ptr+1)=='-' && isdigit(*(ptr+2))) || isdigit(*(ptr+1)))) {
            dataValid=1;
        } else if(!dataValid) {
            printf("Wrong input format!!, example: enque -25\n");
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
    for(char *ptr= string + length; *ptr; --ptr) {
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
    const char dequeA[6] = "deque";
    const char enqueA[6] = "enque";
    fifoEl* stackHead = NULL;
    fifoEl* stackTail = NULL;
    int value;

    //Read input
    //fgets works with buffer, so there is nor problem about geting space char
    while (fgets(array, ARRAY_LENGHT, stdin) != NULL)
    {   
        //change string to lowercase
        toLowercase(array);

        if(strncmp(array, dequeA, (sizeof(dequeA)/sizeof(char))-1) == 0) {
                deque(&stackHead, &stackTail);
            }
        else if(strncmp(array, enqueA, (sizeof(enqueA)/sizeof(char))-1) == 0) {
                if(!validateEnqueFunction(array, stringValue)) {
                    enque(&stackHead, &stackTail, stringToValue(stringValue));
                }      
            }
        else {
             printf("%s, funciotn unknown. Please repeat.\n", array);
        }
        
    }
    return 0;
}