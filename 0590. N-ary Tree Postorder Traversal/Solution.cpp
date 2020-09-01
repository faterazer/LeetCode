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
    vector<int> postorder_MK1(Node *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        stack<Node*> stk;
        stk.push(root);
        Node *last = nullptr;
        while (!stk.empty()) {
            Node *p = stk.top();
            if (p->children.empty() || p->children.back() == last) {
                stk.pop();
                ret.emplace_back(p->val);
                last = p;
            }
            else {
                for (auto it = p->children.rbegin(); it != p->children.rend(); it++)
                    stk.push(*it);
            }
        }
        return ret;
    }

    vector<int> postorder_MK2(Node *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        stack<Node*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            Node *p = stk.top();
            stk.pop();
            ret.emplace_back(p->val);
            for (size_t i = 0; i < p->children.size(); i++)
                stk.emplace(p->children[i]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
