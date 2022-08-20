#include <algorithm>
#include <stack>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        vector<TreeNode*> stk;
        for (const int& e : nums) {
            TreeNode* p = new TreeNode(e);
            while (!stk.empty() && stk.back()->val < p->val) {
                p->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = p;
            stk.emplace_back(p);
        }
        return stk.front();
    }
};
