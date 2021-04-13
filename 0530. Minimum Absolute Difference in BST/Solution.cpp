#include <algorithm>
#include <numeric>
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
    int getMinimumDifference_MK1(TreeNode *root)
    {
        TreeNode *pre = nullptr;
        int ans = numeric_limits<int>::max();
        inorder(root, pre, ans);
        return ans;
    }

    int getMinimumDifference_MK2(TreeNode *root)
    {
        int ans = numeric_limits<int>::max();
        TreeNode *pre = nullptr;
        while (root) {
            if (pre)
                ans = min(ans, abs(root->val - pre->val));
            if (!root->left) {
                pre = root;
                root = root->right;
            }
            else {
                TreeNode *succ = getSuccessor(root);
                if (!succ->right) {
                    succ->right = root;
                    root = root->left;
                }
                else {
                    succ->right = nullptr;
                    pre = root;
                    root = root->right;
                }
            }
        }
        return ans;
    }

private:
    void inorder(TreeNode *root, TreeNode *&pre, int &ans)
    {
        if (!root)
            return;
        inorder(root->left, pre, ans);
        if (pre)
            ans = min(abs(root->val - pre->val), ans);
        pre = root;
        inorder(root->right, pre, ans);
    }

    TreeNode* getSuccessor(TreeNode *root)
    {
        TreeNode *p = root->left;
        while (p->right && p->right != root)
            p = p->right;
        return p;
    }
};
