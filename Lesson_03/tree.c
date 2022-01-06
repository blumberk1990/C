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
        case '-':
            c= a - b;
            break;
        case '/':
            c= a - b;
            break;
        }
        
        element->value = c;
        element->isValComputed=1;
    }
}

Node* newNode(Node element) {
    Node* newElement = (Node*)malloc(sizeof(Node));
    *newElement = element;
    return newElement;
}

void clearTree(Node* element) {
    if(element == NULL) 
        return;
    clearTree(element->left);
    clearTree(element->right);
    free(element);
}

int isArgument(char c) {
    return (c>='0' && c<='9');
}

void parseData(Node** element, char* string, int *stringPtr) {
    char c = string[*stringPtr];
    (*stringPtr)++;
    if(c == 0) 
        return;
    if(isArgument(c)) {
        *element = newNode(createValue(c-'0'));
    } else {
        Node* newElement = newNode(createOperation(c));
        parseData(&(newElement->left), string, stringPtr);
        parseData(&(newElement->right), string, stringPtr);
        *element = newElement;
    }

}

void convertToPostfix(char input[], char output[])
{
    int inputPtr = 0;
    int outputPtr = 0;
    int characterMemPtr = 0;
    char characterMem[10];
    while(input[inputPtr]!=0) {
        if(isArgument(input[inputPtr])) {
            output[outputPtr] = input[inputPtr];
            inputPtr++;
            outputPtr++;
        } else {
            if(input[inputPtr] != ')') {
                characterMem[characterMemPtr] = input[inputPtr];
                inputPtr++;
                characterMemPtr++;    
            } else {
                characterMemPtr--;
                while(characterMem[characterMemPtr] != '(') {
                    output[outputPtr] = characterMem[characterMemPtr];
                    characterMemPtr--;
                    outputPtr++;
                }
                characterMem[characterMemPtr] = 0;
                inputPtr++;
            }
        }
    }
    characterMemPtr--;
    for(; characterMemPtr>=0; --characterMemPtr) {
        output[outputPtr] = characterMem[characterMemPtr];
        outputPtr++;
        inputPtr++;
    }
    output[outputPtr] = 0;
}

int main(int argc, char** argv) {

    //12+
    char testInput[32] = "1+2";
    //12+34+*
    //char testInput[32] = "((1+2)*(3+4))";
    //123*+
    //char testInput[32] = "1+2*3";
    char testOutput[32];
    convertToPostfix(testInput, testOutput);
    printf("%s = %s\n", testInput, testOutput);

    Node* root;
    int inputPtr = 0;
    parseData(&root, argv[1], &inputPtr);

    printNode(root,0);
    evaluate(root);
    printf("\n\n\n");
    printNode(root,0);
    clearTree(root);
    return 0;
}