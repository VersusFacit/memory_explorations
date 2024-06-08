#include <stdio.h>
#include <stddef.h>

int main() {
    // Example 1: Pointer difference
    int array[] = {10, 20, 30, 40, 50};
    int *ptr1 = &array[1];  // Points to 20
    int *ptr2 = &array[4];  // Points to 50

    ptrdiff_t diff = ptr2 - ptr1;
    printf("Difference between ptr2 and ptr1: %td elements\n", diff);

    // Example 2: Negative pointer difference
    ptrdiff_t negativeDiff = ptr1 - ptr2;
    printf("Negative difference: %td elements\n", negativeDiff);

    // Example 3: Pointer arithmetic
    int *start = array;
    int *end = array + 5;
    ptrdiff_t length = end - start;
    printf("Array length: %td elements\n", length);

    return 0;
}
