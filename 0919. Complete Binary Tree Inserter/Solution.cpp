#include <queue>
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

class CBTInserter {
public:
    CBTInserter(TreeNode* root)
        : root(root)
    {
        candidates.emplace(root);
        while (candidates.front()->right) {
            TreeNode* p = candidates.front();
            candidates.pop();
            if (p->left)
                candidates.emplace(p->left);
            if (p->right)
                candidates.emplace(p->right);
        }
        if (candidates.front()->left)
            candidates.emplace(candidates.front()->left);
    }

    int insert(int val)
    {
        TreeNode* p = new TreeNode(val);
        candidates.emplace(p);
        int res = candidates.front()->val;
        if (!candidates.front()->left)
            candidates.front()->left = p;
        else {
            candidates.front()->right = p;
            candidates.pop();
        }
        return res;
    }

    TreeNode* get_root()
    {
        return root;
    }

private:
    TreeNode* root;
    queue<TreeNode*> candidates;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
