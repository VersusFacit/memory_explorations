#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define SIZE 3

#define PRINT_ARRAY(ptr, type, format, desc)                 \
    do {                                                     \
        printf("\nSize of " #type ": %lu bytes\n", sizeof(type)); \
        printf("%s\n", desc);                                \
        for (int i = 0; i < SIZE; i++) {                     \
            printf(#type "Ptr[%d]: %p, value: " format "\n", i, (void*)(ptr + i), ptr[i]); \
        }                                                    \
    } while (0)

int main(void) {
    char charArray[SIZE] = {'a', 'b', 'c'};
    unsigned char unsignedCharArray[SIZE] = {65, 66, 67}; // ASCII for 'A', 'B', 'C'
    short shortArray[SIZE] = {100, 200, 300};
    unsigned short unsignedShortArray[SIZE] = {100, 200, 300};
    int intArray[SIZE] = {1000, 2000, 3000};
    unsigned int unsignedIntArray[SIZE] = {100, 200, 300};
    long longArray[SIZE] = {10000L, 20000L, 30000L};
    unsigned long unsignedLongArray[SIZE] = {10000UL, 20000UL, 30000UL};
    float floatArray[SIZE] = {1.1f, 2.2f, 3.3f};
    double doubleArray[SIZE] = {1.11, 2.22, 3.33};
    long long longLongArray[SIZE] = {100000LL, 200000LL, 300000LL};
    unsigned long long unsignedLongLongArray[SIZE] = {100000ULL, 200000ULL, 300000ULL};
    long double longDoubleArray[SIZE] = {1.111L, 2.222L, 3.333L};

    /*
     * intptr_t: A signed integer type capable of holding a pointer value, useful
     * 	         for pointer arithmetic where negative values might be relevant.
     * uintptr_t: An unsigned integer type capable of holding a pointer value, useful
     *            for bitwise operations and address calculations that should not
     *            involve negative values.
     */

    size_t sizeTArray[SIZE] = {10, 20, 30};
    ptrdiff_t ptrdiffTArray[SIZE] = {100, 200, 300};
    intptr_t intptrTArray[SIZE] = {1000, 2000, 3000};
    uintptr_t uintptrTArray[SIZE] = {1000, 2000, 3000};

    /*
     * Fixed-width integer types (like int8_t, uint8_t, int16_t, uint16_t,
     * int32_t, uint32_t, int64_t, and uint64_t) exist to ensure consistent and
     * predictable sizes across different systems and compilers. These types are
     * defined in the <stdint.h> header file and are part of the C99 standard.
     */
    int8_t int8Array[SIZE] = {10, 20, 30};
    uint8_t uint8Array[SIZE] = {10, 20, 30};
    int16_t int16Array[SIZE] = {100, 200, 300};
    uint16_t uint16Array[SIZE] = {100, 200, 300};
    int32_t int32Array[SIZE] = {1000, 2000, 3000};
    uint32_t uint32Array[SIZE] = {1000, 2000, 3000};
    int64_t int64Array[SIZE] = {100000LL, 200000LL, 300000LL};
    uint64_t uint64Array[SIZE] = {100000ULL, 200000ULL, 300000ULL};

    PRINT_ARRAY(charArray, char, "%c", "Stores small character values, typically used for text");
    PRINT_ARRAY(unsignedCharArray, unsigned char, "%u", "Similar to char but can store values from 0 to 255");
    PRINT_ARRAY(shortArray, short, "%d", "Stores small integer values, useful for saving memory in large arrays");
    PRINT_ARRAY(unsignedShortArray, unsigned short, "%u", "Similar to short but can only represent non-negative values");
    PRINT_ARRAY(intArray, int, "%d", "Standard integer type, widely used for numerical calculations");
    PRINT_ARRAY(unsignedIntArray, unsigned int, "%u", "Similar to int but can only represent non-negative values");
    PRINT_ARRAY(longArray, long, "%ld", "Used for larger integer values than int");
    PRINT_ARRAY(unsignedLongArray, unsigned long, "%lu", "Similar to long but can only represent non-negative values");
    PRINT_ARRAY(floatArray, float, "%.2f", "Used for single-precision floating-point values, common in graphics and scientific calculations");
    PRINT_ARRAY(doubleArray, double, "%.2f", "Used for double-precision floating-point values, providing more precision than float");
    PRINT_ARRAY(longLongArray, long long, "%lld", "Used for very large integer values");
    PRINT_ARRAY(unsignedLongLongArray, unsigned long long, "%llu", "Similar to long long but can only represent non-negative values");
    PRINT_ARRAY(longDoubleArray, long double, "%.3Lf", "Used for extended precision floating-point values");
    PRINT_ARRAY(int8Array, int8_t, "%d", "Fixed-width 8-bit integer, ensures consistent size across platforms");
    PRINT_ARRAY(uint8Array, uint8_t, "%u", "Fixed-width 8-bit unsigned integer");
    PRINT_ARRAY(int16Array, int16_t, "%d", "Fixed-width 16-bit integer");
    PRINT_ARRAY(uint16Array, uint16_t, "%u", "Fixed-width 16-bit unsigned integer");
    PRINT_ARRAY(int32Array, int32_t, "%d", "Fixed-width 32-bit integer");
    PRINT_ARRAY(uint32Array, uint32_t, "%u", "Fixed-width 32-bit unsigned integer");
    PRINT_ARRAY(int64Array, int64_t, "%lld", "Fixed-width 64-bit integer");
    PRINT_ARRAY(uint64Array, uint64_t, "%llu", "Fixed-width 64-bit unsigned integer");

    PRINT_ARRAY(sizeTArray, size_t, "%zu", "size_t: An unsigned type used for representing sizes of objects and memory. Commonly used for array indexing and loop counters where negative values are not needed.");
    PRINT_ARRAY(ptrdiffTArray, ptrdiff_t, "%td", "ptrdiff_t: A signed type used for representing the difference between two pointers. It is typically used in pointer arithmetic and array indexing.");
    PRINT_ARRAY(intptrTArray, intptr_t, "%zd", "intptr_t: A signed integer type that is capable of holding a pointer value. Useful for casting pointers to integers for arithmetic or hashing operations.");
    PRINT_ARRAY(uintptrTArray, uintptr_t, "%zu", "uintptr_t: An unsigned integer type that can hold a pointer value. Often used for bitwise operations and address calculations where the pointer is treated as a non-negative integer.");

    return 0;
}
