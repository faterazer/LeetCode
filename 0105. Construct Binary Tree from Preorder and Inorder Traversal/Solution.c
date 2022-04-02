#include <stddef.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* builder(int* preorder, int preorderSize, int idx, int* inorder, int l, int r)
{
    if (idx >= preorderSize || l > r)
        return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[idx];
    int m = l;
    while (m <= r && inorder[m] != preorder[idx])
        m += 1;
    root->left = builder(preorder, preorderSize, idx + 1, inorder, l, m - 1);
    root->right = builder(preorder, preorderSize, idx + m - l + 1, inorder, m + 1, r);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    return builder(preorder, preorderSize, 0, inorder, 0, inorderSize);
}
