#include <stdio.h>
#include <inttypes.h>

int main(void) {

    unsigned int testValue = 0x1;
    char *bytePointer = (char *)&testValue;

    volatile uint32_t i=0x01234567;
    char *res0 = ((*((uint8_t *)(&i))) == 0x67) ? "Little Endian" : "Big Endian";

    char arr[] = {2, 7};
    void *ptr = (void *)&arr[0];

    char res1 = *(char *)ptr;
    short res2 = *(short *)ptr;


    char arr2[] = {2, 0, 0, 64};
    void *ptr2 = (void*)&arr2[0];
    int res3 = *(int *)ptr2;

    printf(
        "  ---- Let's look at endians and some of their implications ----    \n"
        "                                                                    \n"
        "  Preliminary definitions:                                          \n"
        "     Most Significant Byte (MSB): The byte in a multi-byte number   \n"
        "     that has the greatest value place. It contains the highest     \n"
        "     order bits.                                                    \n"
        "                                                                    \n"
        "     Least Significant Byte (MSB): The byte in a multi-byte number  \n"
        "     that has the lowest value place. It contains the lowest order  \n"
        "     bits.                                                          \n"
        "                                                                    \n"
        "  Memory layout for 0x01234567:                                     \n"
        "     |                                                              \n"
        "     |  [[Big Endian]]                                              \n"
        "     |  Address: 0x00  0x01  0x02  0x03                             \n"
        "     |  Value  : 01    23    45    67                               \n"
        "     |          MSB               LSB                               \n"
        "     | The MSB is at the lowest address, the LSB is at the highest. \n"
        "     |                                                              \n"
        "     | [[Little Endian]]                                            \n"
        "     | Address: 0x00  0x01  0x02  0x03                              \n"
        "     | Value  : 67    45    23    01                                \n"
        "     |          LSB               MSB                               \n"
        "     | The LSB is at the lowest address, the MSB is at the highest. \n"
        "     |                                                              \n"
        "  This is being run on a %s system!                                 \n"
        "                                                                    \n"
        "  The main event:                                                   \n"
        "     *  Logic Representation:                                       \n"
        "     *  Memory Representation:                                      \n"
        "     *    0x00:  0000 0010  (2)                                     \n"
        "     *    0x01:  0000 0111  (7)                                     \n"
        "     *                                                              \n"
        "     *  On a 'Little Endian' system, the lowest address byte of a   \n"
        "     *      multi-byte type is treated as the least significant.    \n"
        "     *      This order is reversed from the raw bits in memory.     \n"
        "     *                                                              \n"
        "     *  void *ptr = (void *)&arr[0]                                 \n"
        "     *     First byte cast to char:     %d (2)                      \n"
        "     *     First byte cast to short:    %d (1794 little or 519 big) \n"
        "     *                                                              \n"
        "     *  Memory Representation:                                      \n"
        "     *    0x00:  0000 0010  (2)                                     \n"
        "     *    0x01:  0000 0000  (0)                                     \n"
        "     *    0x02:  0000 0000  (0)                                     \n"
        "     *    0x03:  0100 0000  (0)                                     \n"
        "     *                                                              \n"
        "     *    Combined as int:                                          \n"
        "     *       little: 0x03 0x02 0x01 0x00   +read them right to left \n"
        "     *       big:    0x00 0x01 0x02 0x03   +read them left to right \n"
        "     *                                                              \n"
        "     *     And here's the little rendered in decimal: %d            \n"
        "     *         2^30 + 2                                             \n"
        "     *         0100 0000 | 0000 0000 | 0000 0000 | 0000 0010        \n"
        "                                                                    \n"
        "   In conclusion, a little endian system stores the                 \n"
        "   bytes of a multi-byte value in memory with the                   \n"
        "   least significant byte at the lowest memory address.             \n"
        "   This means that when reading the raw bits in memory              \n"
        "   across the byte boundaries defined by the type, the              \n"
        "   system interprets bytes in reverse order to determine            \n"
        "   the value.                                                       \n"
        , res0, res1, res2, res3
    );

    return 0;
}

