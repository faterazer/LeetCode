#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* __sortedArrayToBST(int *nums, int left, int right)
{
    if (left > right)
        return NULL;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = left + ((right - left) >> 1);
    root->val = nums[mid];
    root->left = __sortedArrayToBST(nums, left, mid - 1);
    root->right = __sortedArrayToBST(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int *nums, int numsSize)
{
    return __sortedArrayToBST(nums, 0, numsSize - 1);
}
