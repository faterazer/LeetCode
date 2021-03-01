#include <stdlib.h>

typedef struct {
    int *preSum;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *numArray = (NumArray*)malloc(sizeof(NumArray));
    numArray->size = numsSize + 1;
    numArray->preSum = (int*)malloc(sizeof(int) * numArray->size);
    numArray->preSum[0] = 0;
    for (int i = 0; i < numsSize; i++)
        numArray->preSum[i + 1] = numArray->preSum[i] + nums[i];
    return numArray;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return obj->preSum[j + 1] - obj->preSum[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->preSum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
