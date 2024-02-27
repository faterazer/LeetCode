#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root);
private:
    int diameterOfBinaryTree(TreeNode *root, int &diameter);
};

int Solution::diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    diameterOfBinaryTree(root, diameter);
    return diameter;
}

int Solution::diameterOfBinaryTree(TreeNode *root, int &diameter)
{
    if (!root)
        return -1;
    int left = diameterOfBinaryTree(root->left, diameter) + 1;
    int right = diameterOfBinaryTree(root->right, diameter) + 1;
    diameter = max(diameter, left + right);
    return max(left, right);
}
