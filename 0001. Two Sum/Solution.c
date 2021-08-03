#include "uthash.h"

typedef struct hash {
    int id;            /* we'll use this field as the key */
    int index;
    UT_hash_handle hh; /* makes this structure hashable */
} hash;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int *nums, int numsSize, int target, int *returnSize) {
    hash *map = NULL;
    int *res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        hash *entry = NULL;
        int key = target - nums[i];
        HASH_FIND_INT(map, &key, entry);
        if (entry != NULL) {
            res[0] = entry->index;
            res[1] = i;
            break;
        }
        entry = (hash*)malloc(sizeof(hash));
        entry->id = nums[i];
        entry->index = i;
        HASH_ADD_INT(map, id, entry);
    }
    hash *cur, *tmp;
    HASH_ITER(hh, map, cur, tmp) {
        HASH_DEL(map, cur);
        free(cur);
    }
    free(map);
    return res;
}
