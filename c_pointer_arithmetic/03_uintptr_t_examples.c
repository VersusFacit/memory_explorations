#include <stdio.h>
#include <stdint.h>

int main() {
    // Example 1: Casting pointer to uintptr_t for bitwise operations
    int x = 42;
    int *ptr = &x;

    uintptr_t uintPtrValue = (uintptr_t)ptr;
    printf("Pointer value as uintptr_t: %zu\n", uintPtrValue);

    // Example 2: Performing bitwise operations on uintptr_t
    uintptr_t maskedPtr = uintPtrValue & 0xFFFFFFF0;
    printf("Masked pointer value: %zu\n", maskedPtr);

    // Example 3: Storing and manipulating pointer addresses
    uintptr_t addresses[3];
    addresses[0] = (uintptr_t)ptr;
    addresses[1] = (uintptr_t)(ptr + 1);
    addresses[2] = (uintptr_t)(ptr + 2);

    for (size_t i = 0; i < 3; i++) {
        printf("Stored address %zu: %zu\n", i, addresses[i]);
    }

    // Example 4: Pointer arithmetic using uintptr_t
    uintptr_t address = (uintptr_t)ptr;
    address += sizeof(int);
    int *newPtr = (int *)address;
    printf("New pointer after arithmetic: %p\n", (void*)newPtr);

    return 0;
}
