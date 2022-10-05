#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth)
{
    if (!root)
        return root;
    if (depth == 1) {
        struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        p->val = val;
        p->left = root;
        p->right = NULL;
        return p;
    }
    if (depth == 2) {
        struct TreeNode* lp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        lp->val = val;
        lp->left = root->left;
        lp->right = NULL;
        struct TreeNode* rp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        rp->val = val;
        rp->left = NULL;
        rp->right = root->right;
        root->left = lp;
        root->right = rp;
        return root;
    }
    root->left = addOneRow(root->left, val, depth - 1);
    root->right = addOneRow(root->right, val, depth - 1);
    return root;
}
