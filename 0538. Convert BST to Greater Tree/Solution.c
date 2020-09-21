#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Recursion approach 递归方法
 * Time complexity: O(n)
 * Space Complexity: O(n)
 */
void helper(struct TreeNode *root, int *pre_sum)
{
    if (!root)
        return;
    helper(root->right, pre_sum);
    root->val += *pre_sum;
    *pre_sum = root->val;
    helper(root->left, pre_sum);
}

struct TreeNode *convertBST_MK1(struct TreeNode *root)
{
    int pre_sum = 0;
    helper(root, &pre_sum);
    return root;
}

/**
 * Iteration with a Stack 迭代方法
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
struct TreeNode *convertBST_MK2(struct TreeNode *root)
{
    if (!root)
        return root;
    const int CAPACITY = 512;
    struct TreeNode* stack[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
        stack[i] = NULL;
    int tp = 0;
    int pre_sum = 0;
    struct TreeNode *p = root;
    while (tp || p) {
        while (p) {
            stack[tp++] = p;
            p = p->right;
        }
        p = stack[--tp];
        p->val += pre_sum;
        pre_sum = p->val;
        p = p->left;
    }
    return root;
}

/**
 * Reverse Morris In-order Traversal 反转中序 Morris 遍历
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
struct TreeNode *getSuccessor(struct TreeNode *root)
{
    struct TreeNode *succ = root->right;
    while (succ->left && succ->left != root)
        succ = succ->left;
    return succ;
}

struct TreeNode *convertBST_MK3(struct TreeNode *root)
{
    int pre_sum = 0;
    struct TreeNode *p = root;
    while (p) {
        if (!p->right) {
            p->val += pre_sum;
            pre_sum = p->val;
            p = p->left;
        }
        else {
            struct TreeNode *succ = getSuccessor(p);
            if (!succ->left) {
                succ->left = p;
                p = p->right;
            }
            else {
                succ->left = NULL;
                p->val += pre_sum;
                pre_sum = p->val;
                p = p->left;
            }
        }
    }
    return root;
}
