#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (!root || root == p || root == q)
        return root;
    struct TreeNode* lp = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rp = lowestCommonAncestor(root->right, p, q);
    if (lp && rp)
        return root;
    else if (lp || rp)
        return lp ? lp : rp;
    else
        return NULL;
}
