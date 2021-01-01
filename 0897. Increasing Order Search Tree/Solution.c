#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* inOrder(struct TreeNode *root, struct TreeNode *tail)
{
    if (!root)
        return tail;
    struct TreeNode *head = inOrder(root->left, root);
    root->left = NULL;
    root->right = inOrder(root->right, tail);
    return head;
}

struct TreeNode* increasingBST(struct TreeNode *root)
{
    return inOrder(root, NULL);
}
