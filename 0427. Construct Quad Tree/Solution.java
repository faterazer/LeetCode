class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;


    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}

class Solution {
    public Node construct(int[][] grid) {
        return construct(grid, 0, 0, grid.length);
    }

    private Node construct(int[][] grid, int x, int y, int len) {
        if (len == 1) {
            return new Node(grid[x][y] == 1, true);
        }
        Node res = new Node();
        len >>= 1;
        Node topLeft = construct(grid, x, y, len);
        Node topRight = construct(grid, x, y + len, len);
        Node bottomLeft = construct(grid, x + len, y, len);
        Node bottomRight = construct(grid, x + len, y + len, len);
        if (topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf && topLeft.val == topRight.val && topRight.val == bottomLeft.val && bottomLeft.val == bottomRight.val) {
            res.isLeaf = true;
            res.val = topLeft.val;
        } else {
            res.topLeft = topLeft;
            res.topRight = topRight;
            res.bottomLeft = bottomLeft;
            res.bottomRight = bottomRight;
        }
        return res;
    }
}
