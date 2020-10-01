#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> occured;
        return findTarget(root, k, occured);
    }
private:
    bool findTarget(TreeNode *root, int k, unordered_set<int> &occured)
    {
        if (!root)
            return false;
        if (occured.count(k - root->val))
            return true;
        occured.insert(root->val);
        return findTarget(root->left, k, occured) || findTarget(root->right, k, occured);
    }
};
