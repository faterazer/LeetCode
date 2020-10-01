#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inOrder(struct TreeNode *root, int *arr, int *size)
{
    if (!root)
        return;
    inOrder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inOrder(root->right, arr, size);
}

bool findTarget(struct TreeNode *root, int k)
{
    int arr[10001] = {0}, size = 0;
    inOrder(root, arr, &size);
    int low = 0, high = size - 1;
    while (low < high) {
        int sum = arr[low] + arr[high];
        if (sum < k)
            low += 1;
        else if (sum > k)
            high -= 1;
        else
            return true;
    }
    return false;
}
