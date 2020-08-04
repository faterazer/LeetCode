#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    // DFS
    int maxDepth_MK1(Node *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        for (Node *child : root->children)
            depth = max(depth, maxDepth_MK1(child));
        return depth + 1;
    }

    // BFS
    int maxDepth_MK2(Node *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<Node*> que;
        que.emplace(root);
        while (!que.empty()) {
            int n = que.size();
            depth++;
            for (int i = 0; i < n; i++) {
                Node *p = que.front();
                que.pop();
                for (Node *child : p->children)
                    que.emplace(child);
            }
        }
        return depth;
    }
};
