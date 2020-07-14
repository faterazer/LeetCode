import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean isSameTree_MK1(TreeNode p, TreeNode q) {
        if (p != null && q != null && p.val == q.val)
            return isSameTree_MK1(p.left, q.left) & isSameTree_MK1(p.right, q.right);
        if (p == null && q == null)
            return true;
        else
            return false;
    }

    public boolean isSameTree_MK2(TreeNode p, TreeNode q) {
        Queue<TreeNode> pQue = new LinkedList<TreeNode>();
        Queue<TreeNode> qQue = new LinkedList<TreeNode>();
        pQue.offer(p);
        qQue.offer(q);
        while (!pQue.isEmpty() || !qQue.isEmpty()) {
            TreeNode pNode = pQue.poll();
            TreeNode qNode = qQue.poll();
            if (!check(pNode, qNode))
                return false;
            if (pNode != null) {
                pQue.offer(pNode.left);
                pQue.offer(pNode.right);
                qQue.offer(qNode.left);
                qQue.offer(qNode.right);
            }
        }
        return true;
    }

    private boolean check(TreeNode p, TreeNode q) {
        if (p != null && q != null && p.val == q.val)
            return true;
        else if (p == null && q == null)
            return true;
        else
            return false;
    }
}
