#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define ARRAY_LENGHT 33

#define POP_MODE_PARAM_FIFO 0
#define POP_MODE_PARAM_LIFO 1

// Structure of the double linked list object
typedef struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// Creating new singel object of the type doublelinkedlistEl
Node newdoublelinkedlistEl(int value) {
    Node element = {value, NULL, NULL};
    return element;
}

// Dynamic allocation of the elment
void push(Node** head, Node** tail, int value) {
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->value = value;
    newElement->prev = *tail;
    newElement->next = NULL;
    if(*head == NULL) {
        *head = newElement;
    } else {
        (*tail)->next = newElement;
    }
    *tail = newElement;
}

// Freeing memory according to cfg
// mode = 0 => FIFO
// mode >= 1 => LIFO
int pop(Node** head, Node** tail, int mode) {
    int value;
    Node* oldPtr;
    if(!mode) { 
        oldPtr = *head;
        if(*head == NULL) {
            printf("Error, list is empty!\n");
        } else if((*head) == (*tail)) {
            (*head)->next == NULL;
            *tail = NULL;
        }
        *head = (*head)->next;
        value = oldPtr->value;
        free(oldPtr);
    } else {
        oldPtr = *tail;
        if(*tail == NULL) {
            printf("Error, list is empty!\n");
        } else if ((*head) == (*tail)) {
            (*tail)->next == NULL;
            *head = NULL;
        }
        *tail = (*tail)->prev;
        value = oldPtr->value;
        free(oldPtr);
    }
    return value;
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
    int length = sizeof(string)/sizeof(char);
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
    const char dequeA[6] = "deque";
    const char enqueA[6] = "enque";
    Node* stackHead = NULL;
    Node* stackTail = NULL;
    int value;

    //Read input
    //fgets works with buffer, so there is nor problem about geting space char
    while (fgets(array, ARRAY_LENGHT, stdin) != NULL)
    {   
        //change string to lowercase
        toLowercase(array);

        if(strncmp(array, dequeA, (sizeof(dequeA)/sizeof(char))-1) == 0) {
                //pop(&stackHead, &stackTail, POP_MODE_PARAM_FIFO);
                pop(&stackHead, &stackTail, POP_MODE_PARAM_LIFO);
            }
        else if(strncmp(array, enqueA, (sizeof(enqueA)/sizeof(char))-1) == 0) {
                if(!validateEnqueFunction(array, stringValue)) {
                    push(&stackHead, &stackTail, stringToValue(stringValue));
                }      
            }
        else {
             printf("%s, funciotn unknown. Please repeat.\n", array);
        }
        
    }
    return 0;
}
