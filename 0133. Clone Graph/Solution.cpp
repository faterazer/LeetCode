#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> visited;
        return dfs(node, visited);
    }

private:
    Node* dfs(Node* node, unordered_map<int, Node*>& visited)
    {
        if (visited.count(node->val))
            return visited[node->val];
        Node* res = new Node(node->val, node->neighbors);
        visited[node->val] = res;
        for (size_t i = 0; i < node->neighbors.size(); i++)
            res->neighbors[i] = dfs(node->neighbors[i], visited);
        return res;
    }
};
