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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        stack<TreeNode*> tree1, tree2;
        while (root1) {
            tree1.emplace(root1);
            root1 = root1->left;
        }
        while (root2) {
            tree2.emplace(root2);
            root2 = root2->left;
        }
        vector<int> res;
        while (!tree1.empty() || !tree2.empty()) {
            if (tree2.empty() || (!tree1.empty() && tree1.top()->val <= tree2.top()->val)) {
                res.emplace_back(tree1.top()->val);
                iterNext(tree1);
            }
            else {
                res.emplace_back(tree2.top()->val);
                iterNext(tree2);
            }
                
        }
        return res;
    }

private:
    void iterNext(stack<TreeNode*> &tree) {
        if (tree.empty())
            return;
        TreeNode* res = tree.top();
        tree.pop();
        for (TreeNode *p = res->right; p; p = p->left)
            tree.emplace(p);
    }
};
