#include "lib.h"
#include <stdio.h>
#include <string.h>

static char devId[4];


void initializeDevice() {

    strcpy(devId, "ABC");
}

void connectToDevice(){
    printf("Connected to: %s\n", devId);
}
void disconnectFromDevice(){
    printf("Disconnected from: %s\n", devId);
}