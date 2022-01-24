#include <stdio.h>
#include <windows.h>

#define BUFF_SIZE 1024

int main(int argc, char** argv) {

    HANDLE inputFile;
    HANDLE outpuyFile;
    DWORD noReadBytes;
    DWORD noWrittenBytes;
    CHAR buffer[BUFF_SIZE];

    // check if user gives files name 
    if(argc != 3) {
        printf("Usage: cp input output\n");
        return 1;
    }

    // check input file
    inputFile = CreateFile(argv[1], 
                            GENERIC_READ,
                            FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
    if(inputFile == INVALID_HANDLE_VALUE) {
        printf("Cannot open file %s\n", argv[1]);
        return 2;
    }

    // check output file
    outpuyFile = CreateFile(argv[2], 
                            GENERIC_WRITE,
                            0,
                            NULL,
                            CREATE_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
    if(inputFile == INVALID_HANDLE_VALUE) {
        printf("Cannot open file %s\n", argv[2]);
        return 3;
    }

    // copying file
    while(ReadFile(inputFile, buffer, BUFF_SIZE, &noReadBytes, NULL) && noReadBytes > 0) {
        WriteFile(outpuyFile, buffer, noReadBytes, &noWrittenBytes, NULL);
        if(noReadBytes != noWrittenBytes) {
            printf("Error during copying the file\n");
            return 4;
        }
    }

    // cloesing files
    CloseHandle(inputFile);
    CloseHandle(outpuyFile);

    return 0;
}