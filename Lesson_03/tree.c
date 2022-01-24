#include <stdio.h>
#include <stdlib.h>

#define NO_OP ' '
#define BUFF_LENN 32

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

void convertToPostfix(char input[], char output[]) {
    int inputPtr = 0;
    int outputPtr = 0;
    int characterMemPtr = 0;
    char characterMem[BUFF_LENN];
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

int computePostfix(char expr[]) {
    int exprPtr = 0;
    int stackPtr = 0;
    int stack[BUFF_LENN];
    
    int a = 0;
    int b = 0;
    int c = 0; 
    //No null element
    if(expr == NULL) 
        return 0;
    while(expr[exprPtr] != 0) {
        if(isArgument(expr[exprPtr])) {
            stack[stackPtr] = expr[exprPtr] - '0';
            stackPtr++;
        } else {
            a = stack[--stackPtr]; 
            b = stack[--stackPtr];
            switch (expr[exprPtr]) {
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
                    c= a / b;
                    break;
            }
            stack[stackPtr] = c;
            stackPtr++;
        }
        exprPtr++;
    }
    return stack[--stackPtr];
}

int compute(char expr[]) {
    char postfixExpr[BUFF_LENN];
    int result = 0;
    convertToPostfix(expr, postfixExpr);
    result = computePostfix(postfixExpr);
    return result;
}

int main(int argc, char** argv) {

    //char testInput[32] = "1+2";
    //12+34+*
    //char testInput[32] = "((1+2)*(3+4))";
    //123*+
    //char testInput[32] = "1+2*3";
    //char testOutput[32];
    //convertToPostfix(testInput, testOutput);
    //printf("%s = %s\n", testInput, testOutput);

    //char testInput[BUFF_LENN] = "12+";
    //char testInput[BUFF_LENN] = "123*+";
    //char testInput[BUFF_LENN] = "12+3*";
    //char testInput[BUFF_LENN] = "12+34+*";
    //int result = computePostfix(testInput);
    //printf("computePostfix result = %d\n", result);
    
    //char testInput[32] = "1+2";
    //char testInput[32] = "(1+2)*3";
    char testInput[32] = "((1+2)*(3+4))";
    int result = compute(testInput);
    printf("compute result = %d\n", result);

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