#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() { }

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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<Node*> Q;
        Q.emplace(root);
        while (!Q.empty()) {
            int layer_size = Q.size();
            vector<int> layer;
            for (int i = 0; i < layer_size; ++i) {
                Node* node = Q.front();
                Q.pop();
                layer.emplace_back(node->val);
                for (Node* child : node->children)
                    Q.emplace(child);
            }
            res.emplace_back(layer);
        }
        return res;
    }
};
