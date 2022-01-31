#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>f
#include <stdio.h>


#define BUFF_SIZE 1024

int main(int argc, char** argv) {

    int inputFile;
    int outpuyFile;
    int noReadBytes;
    int noWrittenBytes;
    char buffer[BUFF_SIZE];

    // check if user gives files name 
    if(argc != 3) {
        printf("Usage: cp input output\n");
        return 1;
    }

    // check input file, unix -1
    inputFile = open(argv[1], O_RDONLY);
    if(inputFile == -1) {
        printf("Cannot open file %s\n", argv[1]);
        return 2;
    }

    // check output file
    outpuyFile = creat(argv[2], 0666);
    if(inputFile == -1) {
        printf("Cannot open file %s\n", argv[2]);
        return 3;
    }

    // copying file
    while((noReadBytes = read(inputFile, buffer, BUFF_SIZE)) > 0) {
        noWrittenBytes = write(outpuyFile, buffer, noReadBytes);
        if(noReadBytes != noWrittenBytes) {
            printf("Error during copying the file\n");
            return 4;
        }
    }

    // cloesing files
    close(inputFile);
    close(outpuyFile);

    return 0;
}