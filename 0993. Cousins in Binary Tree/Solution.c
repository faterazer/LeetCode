#include <stdbool.h>
#include <stddef.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, int x, int y, int depth, struct TreeNode *pre, int *x_d, int *y_d, struct TreeNode **x_p, struct TreeNode **y_p)
{
    if (!root || (*x_d && *y_d))
        return;
    if (root->val == x) {
        *x_d = depth;
        *x_p = pre;
    }
    if (root->val == y) {
        *y_d = depth;
        *y_p = pre;
    }
    dfs(root->left, x, y, depth + 1, root, x_d, y_d, x_p, y_p);
    dfs(root->right, x, y, depth + 1, root, x_d, y_d, x_p, y_p);
}

bool isCousins(struct TreeNode *root, int x, int y)
{
    int x_depth = 0, y_depth = 0;
    struct TreeNode *x_parent = NULL, *y_parent = NULL;
    dfs(root, x, y, 1, NULL, &x_depth, &y_depth, &x_parent, &y_parent);
    if (x_depth == y_depth && x_parent != y_parent)
        return true;
    return false;
}
