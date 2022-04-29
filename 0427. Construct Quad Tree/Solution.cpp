#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        return construct(grid, 0, 0, grid.size());
    }

private:
    Node* construct(vector<vector<int>>& grid, int x, int y, int len)
    {
        if (len == 1)
            return new Node(grid[x][y], true);
        Node* res = new Node();
        len /= 2;
        Node* topLeft = construct(grid, x, y, len);
        Node* topRight = construct(grid, x, y + len, len);
        Node* bottomLeft = construct(grid, x + len, y, len);
        Node* bottomRight = construct(grid, x + len, y + len, len);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            res->val = topLeft->val;
            res->isLeaf = true;
        } else {
            res->topLeft = topLeft;
            res->topRight = topRight;
            res->bottomLeft = bottomLeft;
            res->bottomRight = bottomRight;
        }
        return res;
    }
};
