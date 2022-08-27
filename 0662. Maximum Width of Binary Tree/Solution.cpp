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
    int widthOfBinaryTree(TreeNode* root)
    {
        vector<vector<unsigned>> min_max;
        helper(root, 1, 0, min_max);
        unsigned res = 0;
        for (const vector<unsigned>& v : min_max)
            res = max(res, v[1] - v[0] + 1);
        return res;
    }

private:
    void helper(TreeNode* root, unsigned idx, int depth, vector<vector<unsigned>>& min_max)
    {
        if (!root)
            return;
        if (min_max.size() < depth + 1)
            min_max.push_back({ idx, idx });
        else {
            min_max[depth][0] = min(min_max[depth][0], idx);
            min_max[depth][1] = max(min_max[depth][1], idx);
        }
        if (root->left)
            helper(root->left, idx << 1, depth + 1, min_max);
        if (root->right)
            helper(root->right, idx << 1 | 1, depth + 1, min_max);
    }
};
