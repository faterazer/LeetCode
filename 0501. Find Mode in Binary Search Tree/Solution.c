#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inOrder(struct TreeNode *root, struct TreeNode **pre, int *max_count, int *cur_count, int *ret, int *returnSize)
{
    if (!root)
        return;
    inOrder(root->left, pre, max_count, cur_count, ret, returnSize);
    if (*pre && (*pre)->val == root->val)
        (*cur_count)++;
    else
        (*cur_count) = 1;
    if (*cur_count > *max_count) {
        *max_count = *cur_count;
        *returnSize = 1;
    }
    else if (*cur_count == *max_count) {
        if (ret)
            ret[*returnSize] = root->val;
        (*returnSize)++;
    }
    *pre = root;
    inOrder(root->right, pre, max_count, cur_count, ret, returnSize);
}

int* findMode(struct TreeNode *root, int *returnSize)
{
    int max_count = 0;
    int cur_count = 0;
    *returnSize = 0;
    int *ret = NULL;
    struct TreeNode *pre = NULL;
    inOrder(root, &pre, &max_count, &cur_count, ret, returnSize);
    cur_count = 0;
    ret = (int*)malloc(sizeof(int) * (*returnSize));
    *returnSize = 0;
    pre = NULL;
    inOrder(root, &pre, &max_count, &cur_count, ret, returnSize);
    return ret;
}
