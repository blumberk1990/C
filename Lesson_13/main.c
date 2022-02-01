#include <string.h>
#include "lib.h"

char devId[4];

int main() {
    initializeDevice();
    connectToDevice();
    strcpy(devId, "DEF");
    disconnectFromDevice();

    return 0;
}