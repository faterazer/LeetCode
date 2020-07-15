#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 不是真正的 O(1)
// class Solution
// {
// public:
//     vector<int> findMode(TreeNode *root)
//     {
//         vector<int> ret;
//         int max_count = 0, cur_count = 0;
//         TreeNode *pre = nullptr;
//         findMode(root, pre, ret, max_count, cur_count);
//         return ret;
//     }
// private:
//     void findMode(TreeNode *root, TreeNode *&pre, vector<int> &ret, int &max_count, int &cur_count)
//     {
//         if (!root)
//             return;
//         findMode(root->left, pre, ret, max_count, cur_count);
//         if (pre && pre->val == root->val)
//             cur_count++;
//         else
//             cur_count = 1;
//         if (cur_count == max_count)
//             ret.emplace_back(root->val);
//         else if (cur_count > max_count) {
//             ret.clear();
//             ret.emplace_back(root->val);
//             max_count = cur_count;
//         }
//         pre = root;
//         findMode(root->right, pre, ret, max_count, cur_count);
//     }
// };

class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> ret;
        int max_count = 0, cur_count = 0, ret_count = 0;
        TreeNode *pre = nullptr;
        inOrder(root, pre, ret, ret_count, max_count, cur_count);
        ret.resize(ret_count);
        cur_count = 0;
        ret_count = 0;
        pre = nullptr;
        inOrder(root, pre, ret, ret_count, max_count, cur_count);
        return ret;
    }
private:
    void inOrder(TreeNode *root, TreeNode *&pre, vector<int> &ret, int &ret_count, int &max_count, int &cur_count)
    {
        if (!root)
            return;
        inOrder(root->left, pre, ret, ret_count, max_count, cur_count);
        if (pre && pre->val == root->val)
            cur_count++;
        else
            cur_count = 1;
        if (cur_count > max_count) {
            max_count = cur_count;
            ret_count = 1;
        }
        else if (cur_count == max_count) {
            if (ret.size())
                ret[ret_count] = root->val;
            ret_count++;
        }
        pre = root;
        inOrder(root->right, pre, ret, ret_count, max_count, cur_count);
    }
};
