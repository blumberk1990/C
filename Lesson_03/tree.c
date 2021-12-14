#include <stdio.h>
#include <stdlib.h>

#define NO_OP ' '

typedef struct Node {
    char op;
    double value;
    int isValComputed;

    struct Node* left;
    struct Node* right;
} Node;

Node createOperation(char op) {
    Node newElement = {op, 0, 0, NULL, NULL};
    return newElement;
}

Node createValue(double value) {
    Node newElement = {NO_OP, value, 1, NULL, NULL};
    return newElement;
}

void printNode(Node* element, int level) {
    if (element== NULL){
        return;
    }
    for (int i=0; i<level; i++) {
        printf(" ");
    }
    printf("|- ");
    if(element->op != NO_OP) {
        printf("%c\t", element->op);
    }

    if(element->isValComputed) {
        printf("%.2f\n", element->value);
    } else {
        printf("?\n");
    }
    printNode(element->left, level+1);
    printNode(element->right, level+1);
}

void evaluate(Node* element) {
    if(element->op != NO_OP) {
        //No null element
        if(element == NULL)
            return;

        evaluate(element->left);
        evaluate(element->right);
        
        double a = element->left->value;
        double b = element->right->value;
        double c;
        switch (element->op)
        {
        case '+':
            c= a + b;
            break;
        case '*':
            c= a * b;
            break;
        }
        element->value = c;
        element->isValComputed=1;
    }
}

int main() {

    //1+2*3
    Node el1, el2, el3, el4, el5;
    el1 = createValue(1);
    el2 = createOperation('+');
    el3 = createValue(2);
    el4 = createOperation('*');
    el5 = createValue(3);

    el2.left=&el1;
    el2.right=&el4;

    el4.left=&el3;
    el4.right=&el5;

    printNode(&el2,0);
    evaluate(&el2);
    printf("\n\n\n");
    printNode(&el2,0);
    return 0;
}