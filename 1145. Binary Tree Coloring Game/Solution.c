#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* find_node(struct TreeNode* root, int x)
{
    if (!root)
        return NULL;
    if (root->val == x)
        return root;
    struct TreeNode* p = find_node(root->left, x);
    if (p)
        return p;
    return find_node(root->right, x);
}

int count_nodes(struct TreeNode* root)
{
    if (!root)
        return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

bool btreeGameWinningMove(struct TreeNode* root, int n, int x)
{
    struct TreeNode* node_x = find_node(root, x);
    int a = count_nodes(node_x->left), b = count_nodes(node_x->right), c = n - a - b - 1, half = n / 2;
    return a > half || b > half || c > half;
}
