#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signalHandler(int sig) {
    switch(sig) 
    {
        case SIGFPE:
            printf("Arithmetic error\n");
            break;
    }
}

int main(int argc, char** argv) {

    int a, b, c;

    signal(SIGFPE, signalHandler);

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = a / b;

    printf("%d / %d = %d\n", a, b, c);
    return 0;
}