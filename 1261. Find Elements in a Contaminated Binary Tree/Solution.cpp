#include <bit>
#include <stack>
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

class FindElements {
public:
    FindElements(TreeNode* root)
        : tree(root)
    {
    }

    bool find(int target)
    {
        TreeNode *cur = tree;
        unsigned x = target + 1;
        for (int i = 30 - countl_zero(x); i >= 0; --i) {
            if ((x >> i) & 1)
                cur = cur->right;
            else
                cur = cur->left;
            if (!cur)
                return false;
        }
        return true;
    }
    
private:
    TreeNode* tree = nullptr;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
