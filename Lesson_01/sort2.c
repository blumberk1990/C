#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareString(const void* a, const void* b){  
    char** a_ = (char**)a;
    char** b_ = (char**)b;
    return strcmp(*a_, *b_);
}

int compareString1(const void* a, const void* b){  
    char* a_ = (char*)a;
    char* b_ = (char*)b;
    return strcmp(a_, b_);
}

int main()
{
        //ptr for 5 elements array
        char* data[] = {"slon",
                        "arbuz",
                        "bagietka",
                        "ananas",
                        "zloto"};

        char data1[5][20] = {{"slon"},
                        {"arbuz"},
                        {"bagietka"},
                        {"ananas"},
                        {"zloto"}};
                        

    printf("sizeof(data)/sizeof(char*): %d\n sizeof(data): %d\n sizeof(char*): %d\n sizeof(char): %d", sizeof(data)/sizeof(char*), sizeof(data),sizeof(char*), sizeof(char));
    qsort(data, sizeof(data)/sizeof(char*), sizeof(char*), compareString);
    qsort(data1, sizeof(data)/sizeof(char*), 20*sizeof(char), compareString1);

    return 0;
}