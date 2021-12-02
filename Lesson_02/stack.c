#include <stdio.h>
#include <stdlib.h>

typedef struct stackEl {
    int value;
    struct stackEl* next;
} stackEl;

stackEl newStackEl(int value) {
    stackEl el = {value, NULL};
    return el;
}

void push(stackEl** ptr, int value) {
    //Allocate memmory for new element; 
    stackEl* newElement = (stackEl*)malloc(sizeof(stackEl));
    //*(newElement).value, put value to the adress
    newElement->value = value;
    //*(newElement).next, put the value from the address to the address
    newElement->next = *ptr;
    //put neElement to the value from the address *ptr
    *ptr = newElement;
}

int pop(stackEl** ptr) {
    int value;
    stackEl* oldPtr = *ptr;
    
    *ptr = (*ptr)->next;
    value = oldPtr->value;

    free(oldPtr);
    return value;
}

int main() {
    stackEl* stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}