#include <stdlib.h>
#include <string.h>

typedef struct {
    int* tree;
    int* data;
    int size;
} NumArray_Binary_Indexed_Tree;

int lowbit(int x)
{
    return x & -x;
}

void numArrayUpdate(NumArray_Binary_Indexed_Tree* obj, int index, int val)
{
    int diff = val - obj->data[index];
    obj->data[index] = val;
    index += 1;
    while (index < obj->size) {
        obj->tree[index] += diff;
        index += lowbit(index);
    }
}

NumArray_Binary_Indexed_Tree* numArrayCreate(int* nums, int numsSize)
{
    NumArray_Binary_Indexed_Tree* res = (NumArray_Binary_Indexed_Tree*)malloc(sizeof(NumArray_Binary_Indexed_Tree));
    res->data = (int*)malloc(sizeof(int) * numsSize);
    memset(res->data, 0, sizeof(int) * numsSize);
    res->tree = (int*)malloc(sizeof(int) * (numsSize + 1));
    memset(res->tree, 0, sizeof(int) * (numsSize + 1));
    res->size = numsSize + 1;
    for (int i = 0; i < numsSize; ++i)
        numArrayUpdate(res, i, nums[i]);
    return res;
}

int numArraySumRange(NumArray_Binary_Indexed_Tree* obj, int left, int right)
{
    int res = 0;
    right += 1;
    while (right > 0) {
        res += obj->tree[right];
        right -= lowbit(right);
    }
    while (left > 0) {
        res -= obj->tree[left];
        left -= lowbit(left);
    }
    return res;
}

void numArrayFree(NumArray_Binary_Indexed_Tree* obj)
{
    free(obj->data);
    free(obj->tree);
    free(obj);
    obj = NULL;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);

 * int param_2 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/

typedef struct {
    int* tree;
    int size;
} NumArray_Segment_Tree;

NumArray_Segment_Tree* numArrayCreate(int* nums, int numsSize)
{
    NumArray_Segment_Tree* res = (NumArray_Segment_Tree*)malloc(sizeof(NumArray_Segment_Tree));
    res->size = 2 * numsSize;
    res->tree = (int*)malloc(sizeof(int) * res->size);
    for (int i = numsSize; i < res->size; ++i)
        res->tree[i] = nums[i - numsSize];
    for (int i = numsSize - 1; i > 0; --i)
        res->tree[i] = res->tree[i << 1] + res->tree[i << 1 | 1];
    return res;
}

void numArrayUpdate(NumArray_Segment_Tree* obj, int index, int val)
{
    index += obj->size / 2;
    int diff = val - obj->tree[index];
    while (index > 0) {
        obj->tree[index] += diff;
        index >>= 1;
    }
}

int numArraySumRange(NumArray_Segment_Tree* obj, int left, int right)
{
    left += obj->size / 2;
    right += obj->size / 2;
    int res = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            res += obj->tree[left];
            ++left;
        }
        if (right % 2 == 0) {
            res += obj->tree[right];
            --right;
        }
        left >>= 1;
        right >>= 1;
    }
    return res;
}

void numArrayFree(NumArray_Segment_Tree* obj)
{
    free(obj->tree);
    free(obj);
    obj = NULL;
}
