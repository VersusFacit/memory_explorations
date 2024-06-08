#include <stdio.h>
#include <stdint.h>

int main() {
    // Example 1: Casting pointer to intptr_t for arithmetic
    int x = 42;
    int *ptr = &x;

    intptr_t intPtrValue = (intptr_t)ptr;
    printf("Pointer value as intptr_t: %zd\n", intPtrValue);

    // Example 2: Storing pointer differences as intptr_t
    int array[] = {10, 20, 30, 40, 50};
    int *ptr1 = &array[1];
    int *ptr2 = &array[4];

    intptr_t ptrDiff = (intptr_t)ptr2 - (intptr_t)ptr1;
    printf("Pointer difference as intptr_t: %zd bytes\n", ptrDiff);

    // Example 3: Hashing pointer values
    intptr_t hashValue = intPtrValue ^ (intPtrValue >> 16);
    printf("Hashed pointer value: %zd\n", hashValue);

    // Example 4: Pointer comparison using intptr_t
    if ((intptr_t)ptr1 < (intptr_t)ptr2) {
        printf("ptr1 is less than ptr2\n");
    }

    return 0;
}
