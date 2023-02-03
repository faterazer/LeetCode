#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x)
    {
        TreeNode* node_x = find_node(root, x);
        int a = count_nodes(node_x->left), b = count_nodes(node_x->right), c = n - a - b - 1, half = n / 2;
        return a > half || b > half || c > half;
    }

private:
    int count_nodes(TreeNode* root)
    {
        if (!root)
            return 0;
        return count_nodes(root->left) + count_nodes(root->right) + 1;
    }

    TreeNode* find_node(TreeNode* root, int x)
    {
        if (!root)
            return nullptr;
        if (root->val == x)
            return root;
        TreeNode* p = find_node(root->left, x);
        if (p)
            return p;
        return find_node(root->right, x);
    }
};
