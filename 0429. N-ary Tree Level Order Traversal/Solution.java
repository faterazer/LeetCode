import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
}

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int layerSize = queue.size();
            List<Integer> layer = new ArrayList<>();
            while (layerSize-- > 0) {
                Node node = queue.poll();
                assert node != null;
                layer.add(node.val);
                for (Node child : node.children) {
                    queue.offer(child);
                }
            }
            res.add(layer);
        }
        return res;
    }
}
