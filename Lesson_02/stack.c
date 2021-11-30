#include <stdio.h>

typedef struct stackEl {
    int value;
    struct stackEl* next;
} stackEl;

stackEl newStackEl(int value) {
    stackEl el = {value, NULL};
    return el;
}

int main() {
    stackEl el1, el2, el3;

    el1 = newStackEl(1);
    el2 = newStackEl(2);
    el3 = newStackEl(3);

    el3.next = &el2;
    el2.next = &el1;
    el1.next = NULL;
    return 0;
}