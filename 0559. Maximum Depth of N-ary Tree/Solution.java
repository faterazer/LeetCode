import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Node {
    public int val;
    public List<Node> children;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    // DFS
    public int maxDepth_MK1(Node root) {
        if (root == null)
            return 0;
        int depth = 0;
        for (Node child : root.children)
            depth = Math.max(depth, this.maxDepth_MK1(child));
        return depth + 1;
    }

    // BFS
    public int maxDepth_MK2(Node root) {
        if (root == null)
            return 0;
        int depth = 0;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int n = queue.size();
            depth++;
            for (int i = 0; i < n; i++) {
                Node node = queue.poll();
                for (Node child : node.children)
                    queue.offer(child);
            }
        }
        return depth;
    }
}
