#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
