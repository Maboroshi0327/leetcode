#include <stdlib.h>
#include <string.h>

int strStr(char *haystack, char *needle) {
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if (h_len < n_len)
        return -1;

    int *next = malloc(n_len * sizeof(int));
    next[0] = 0;

    // next table
    int j = 0;
    for (int i = 1; i < n_len; i++) {
        while (needle[i] != needle[j] && j > 0)
            j = next[j - 1];

        if (needle[i] == needle[j])
            j++;

        next[i] = j;
    }

    // match
    j = 0;
    for (int i = 0; i < h_len; i++) {
        while (haystack[i] != needle[j] && j > 0)
            j = next[j - 1];

        if (haystack[i] == needle[j])
            j++;

        if (j == n_len) {
            free(next);
            return i - n_len + 1;
        }
    }

    free(next);
    return -1;
}
