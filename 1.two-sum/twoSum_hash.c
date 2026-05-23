#include <stdlib.h>

#include "uthash.h"

typedef struct {
    int index;
    int value;
    UT_hash_handle hh;
} hashTable;

void deleteHashTable(hashTable *head) {
    hashTable *current = NULL, *tmp = NULL;
    HASH_ITER(hh, head, current, tmp) {
        HASH_DEL(head, current);
        free(current);
    }
    head = NULL;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 2;
    int *result = malloc(2 * sizeof(int));

    hashTable *head = NULL, *entry = NULL;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        HASH_FIND_INT(head, &complement, entry);

        if (entry != NULL) {
            result[0] = entry->index;
            result[1] = i;

            deleteHashTable(head);

            return result;
        }

        entry = malloc(sizeof(hashTable));
        entry->index = i;
        entry->value = nums[i];
        HASH_ADD_INT(head, value, entry);
    }

    deleteHashTable(head);

    returnSize = 0;
    free(result);
    result = NULL;

    return result;
}
