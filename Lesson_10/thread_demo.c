#include <windows.h>
#include <stdio.h>

#define NO_THREADS 2

DWORD WINAPI thread1Work(LPVOID ilParam) {
    for(int i=0; i<10; i++) {
        printf("%d\n", 2*i);
        Sleep(1000);//1000ms
    }
    return 0;
}

DWORD WINAPI thread2Work(LPVOID ilParam) {
    for(int i=0; i<10; i++) {
        printf("%d\n", 2*i+1);
        Sleep(1000);//1000ms
    }
    return 0;
}

int main() {
    
    HANDLE hThread[NO_THREADS];
    DWORD dwThreadId[NO_THREADS];

    hThread[0] = CreateThread(
        NULL,                   //Security attributes
        0,                      //Default stack size
        thread1Work,          //Worker function
        NULL,                   //Arguments for thread function
        0,                      //Default creation flag
        &dwThreadId[0]
    );

    hThread[1] = CreateThread(
        NULL,                   //Security attributes
        0,                      //Default stack size
        thread2Work,          //Worker function
        NULL,                   //Arguments for thread function
        0,                      //Default creation flag
        &dwThreadId[1]
    );

    WaitForMultipleObjects(NO_THREADS, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);



    return 0;
}

