#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapPush(int *heap, int *size, int val) {
    heap[(*size)++] = val;
    int index = *size;
    for (int parent = index / 2; parent > 0 && heap[parent - 1] > heap[index - 1]; index = parent, parent /= 2) 
        swap(heap + parent - 1, heap + index - 1);
}

void heapPop(int *heap, int *size)
{
    swap(heap, heap + --(*size));
    int i = 0, j;
    while (i < *size / 2) {
        int left = (i + 1) * 2 - 1;
        int right = (i + 1) * 2;
        if (left >= *size)
            break;
        else if (right >= *size)
            j = left;
        else
            j = heap[left] < heap[right] ? left : right;
        if (heap[i] > heap[j])
            swap(heap + i, heap + j);
        else
            break;
        i = j;
    }
}

typedef struct
{
    int *min_heap;
    int size;
    int k;
} KthLargest;

KthLargest* kthLargestCreate(int k, int *nums, int numsSize)
{
    KthLargest *kthLargest = (KthLargest*)malloc(sizeof(KthLargest));
    kthLargest->k = k;
    kthLargest->min_heap = (int*)malloc(sizeof(int) * (k + 1));
    kthLargest->size = 0;
    for (int i = 0; i < numsSize; i++) {
        heapPush(kthLargest->min_heap, &(kthLargest->size), nums[i]);
        if (kthLargest->size > k)
            heapPop(kthLargest->min_heap, &(kthLargest->size));
    }
    return kthLargest;
}

int kthLargestAdd(KthLargest *obj, int val)
{
    heapPush(obj->min_heap, &(obj->size), val);
    if (obj->size > obj->k)
        heapPop(obj->min_heap, &(obj->size));
    return obj->min_heap[0];
}

void kthLargestFree(KthLargest *obj)
{
    obj->k = 0;
    obj->size = 0;
    free(obj->min_heap);
    obj->min_heap = NULL;
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
