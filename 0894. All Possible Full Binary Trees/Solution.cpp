#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    Solution()
        : f(11)
    {
        f[1] = { new TreeNode(0) };
        for (int i = 2; i < 11; i++)
            for (int j = 1; j < i; j++)
                for (TreeNode* left : f[j])
                    for (TreeNode* right : f[i - j])
                        f[i].push_back(new TreeNode(0, left, right));
    }

    vector<TreeNode*> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return f[0];
        return f[(n + 1) >> 1];
    }

private:
    vector<vector<TreeNode*>> f;
};
