#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    if (root->val < val) {
        p->left = root;
        return p;
    }
    struct TreeNode* cur = root;
    while (cur->right && cur->right->val > val)
        cur = cur->right;
    p->left = cur->right;
    cur->right = p;
    return root;
}
