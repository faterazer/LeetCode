#include <stack>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node *p = stk.top();
            stk.pop();
            ret.emplace_back(p->val);
            for (auto it = p->children.rbegin(); it != p->children.rend(); it++)
                stk.push(*it);
        }
        return ret;
    }
};
