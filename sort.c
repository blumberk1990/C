#include <stdio.h>
#include <stdlib.h>

/*Return:
        1 when a is bigger than b
        0 when a is equal to b
        -1 when a is smaller than b*/
int compareAscending(const void* a, const void* b) {
    return (((*(int*)a) > (*(int*)b)) - ((*(int*)a) < (*(int*)b)));
}

int compareDescending(const void* a, const void* b) {
    return (((*(int*)b) > (*(int*)a)) - ((*(int*)b) < (*(int*)a)));
}

int compareEvenNextOddDescending(const void* a, const void* b) {
    int a_=*(int*)a;
    int b_=*(int*)b;

    //If both are odd put greater first
    if(a_&1 && b_&1) {
        return b_-a_;
    }
    //If both are even put greater first
    if(!(a_&1) && !(b_&1)) {
        return b_-a_;
    }

    //If a is odd, put b first
    if(a_&1) {
        return 1;
    }

    //If a is even, put a first
    return -1;
}

int compareEvenNextOddAscending(const void* a, const void* b) {
    int a_=*(int*)a;
    int b_=*(int*)b;

    //If both are odd put smaller first
    if(a_&1 && b_&1) {
        return a_-b_;
    }
    //If both are even put smaller first
    if(!(a_&1) && !(b_&1)) {
        return a_-b_;
    }

    //If a is odd, put b first
    if(a_&1) {
        return 1;
    }

    //If a is even, put a first
    return -1;
}

int compareOddNextEvenDescending(const void* a, const void* b) {
    int a_=*(int*)a;
    int b_=*(int*)b;

    //If both are odd put greater first
    if(a_&1 && b_&1) {
        return b_-a_;
    }
    //If both are even put greater first
    if(!(a_&1) && !(b_&1)) {
        return b_-a_;
    }

    //If a is even, put b first
    if(!(a_&1)) {
        return 1;
    }

    //If a is odd, put a first
    return -1;
}

int compareOddNextEvenAscending(const void* a, const void* b) {
    int a_=*(int*)a;
    int b_=*(int*)b;

    //If both are odd put greater first
    if(a_&1 && b_&1) {
        return a_-b_;
    }
    //If both are even put greater first
    if(!(a_&1) && !(b_&1)) {
        return a_-b_;
    }

    //If a is even, put b first
    if(!(a_&1)) {
        return 1;
    }

    //If a is odd, put a first
    return -1;
}




int main() {

    int data[]={1,2,8,2,4,12,65};


    // 1. ptr to the first element of the array
    // 2. number of elements
    // 3. size of the each element in the array
    // 4. funtion that compares two elements
    //qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareAscending);

    //qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareDescending);

    //qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareEvenNextOddDescending);
    //qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareEvenNextOddAscending);

    //qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareOddNextEvenDescending);
    qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareOddNextEvenAscending);
    qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareOddNextEvenAscending);
    qsort(data, sizeof(data)/sizeof(*data), sizeof(int), compareOddNextEvenAscending);
    return 0;
}