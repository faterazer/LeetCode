#include <string>
#include <vector>
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
    vector<string> binaryTreePaths(TreeNode *root);
private:
    void binaryTreePaths(TreeNode *root, vector<string> &path_vec, string path);
};

vector<string> Solution::binaryTreePaths(TreeNode *root)
{
    vector<string> path_vec;
    if (!root)
        return path_vec;
    binaryTreePaths(root, path_vec, to_string(root->val));
    return path_vec;
}

void Solution::binaryTreePaths(TreeNode *root, vector<string> &path_vec, string path)
{
    if (!root->left && !root->right) {
        path_vec.emplace_back(path);
        return;
    }
    if (root->left)
        binaryTreePaths(root->left, path_vec, path + "->" + to_string(root->left->val));
    if (root->right)
        binaryTreePaths(root->right, path_vec, path + "->" + to_string(root->right->val));
}
