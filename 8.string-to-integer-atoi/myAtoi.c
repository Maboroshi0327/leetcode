#include <stdint.h>

int myAtoi(char *s) {
    int sign = 1;
    int result = 0;

    int i = 0;
    while (s[i] != '\0' && s[i] == ' ')
        i++;

    switch (s[i]) {
        case '-':
            sign = -1;
        case '+':
            i++;
    }

    while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9') {
        if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && s[i] > '7')) {
            result = (sign == 1) ? INT32_MAX : INT32_MIN;
            return result;
        }
        result *= 10;
        result += s[i] - '0';
        i++;
    }

    result *= sign;
    return result;
}
