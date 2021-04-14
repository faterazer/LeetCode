from _typeshed import SupportsItemAccess


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def getMinimumDifference_MK1(self, root: TreeNode) -> int:
        vals = []

        def inOrder(root: TreeNode) -> None:
            if root.left:
                inOrder(root.left)
            vals.append(root.val)
            if root.right:
                inOrder(root.right)

        inOrder(root)
        return min(abs(a - b) for a, b in zip(vals, vals[1:]))

    def getMinimumDifference_MK2(self, root: TreeNode) -> int:
        stack = []
        p = root
        pre, ans = None, float('inf')
        while p or stack:
            while p:
                stack.append(p)
                p = p.left
            p = stack.pop()
            if pre:
                ans = min(ans, abs(p.val - pre.val))
            pre = p
            p = p.right
        return ans

    def getMinimumDifference_MK3(self, root: TreeNode) -> int:
        def getSuccessor(root: TreeNode) -> TreeNode:
            p = root.left
            while p.right and p.right != root:
                p = p.right
            return p
        
        ans = float('inf')
        pre = None
        while root:
            if pre:
                ans = min(ans, abs(root.val - pre.val))
            if not root.left:
                pre = root
                root = root.right
            else:
                succ = getSuccessor(root)
                if succ.right:
                    succ.right = None
                    pre = root
                    root = root.right
                else:
                    succ.right = root
                    root = root.left
        return ans
