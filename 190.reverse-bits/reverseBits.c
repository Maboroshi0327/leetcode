#include <stdint.h>

int reverseBits(int n) {
    uint32_t result = (uint32_t)n;

    result = ((result >> 16) & 0x0000FFFF) | ((result << 16) & 0xFFFF0000);
    result = ((result >> 8) & 0x00FF00FF) | ((result << 8) & 0xFF00FF00);
    result = ((result >> 4) & 0x0F0F0F0F) | ((result << 4) & 0xF0F0F0F0);
    result = ((result >> 2) & 0x33333333) | ((result << 2) & 0xCCCCCCCC);
    result = ((result >> 1) & 0x55555555) | ((result << 1) & 0xAAAAAAAA);

    return (int)result;
}
