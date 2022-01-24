#include <stdio.h>

#define BUFF_SIZE 1024

int main(int argc, char** argv) {
    
    FILE* inputFile;
    FILE* outputFile;
    int noReadBytes;
    int noWrittenBytes;
    char buffer[BUFF_SIZE];

    // check if user gives files name 
    if(argc != 3) {
        printf("Usage: cp input output\n");
        return 1;
    }

    // check input file
    inputFile = fopen(argv[1], "rb");
    if(inputFile == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        return 2;
    }

    // check output file
    outputFile = fopen(argv[2], "wb");
    if(outputFile == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 3;
    }

    // copying file
    while((noReadBytes = fread(buffer, sizeof(char), BUFF_SIZE, inputFile)) > 0) {
        noWrittenBytes = fwrite(buffer, sizeof(char), noReadBytes, outputFile);
        if(noReadBytes != noWrittenBytes) {
            printf("Error during copying the file\n");
            return 4;
        }
    }

    // cloesing files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}