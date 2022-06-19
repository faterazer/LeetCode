#include <unordered_map>
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
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        unordered_map<int, int> cnt;
        int max_val = 0;
        dfs(root, cnt, max_val);
        vector<int> res;
        for (const auto& it : cnt)
            if (it.second == max_val)
                res.emplace_back(it.first);
        return res;
    }

private:
    int dfs(TreeNode* root, unordered_map<int, int>& cnt, int& max_val)
    {
        if (!root)
            return 0;
        int res = root->val + dfs(root->left, cnt, max_val) + dfs(root->right, cnt, max_val);
        max_val = max(max_val, ++cnt[res]);
        return res;
    }
};
