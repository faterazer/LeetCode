class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sumRootToLeaf_MK1(self, root: TreeNode) -> int:
        '''
        Recursive Preorder Traversal.
        Time complexity: O(N). N is a number of nodes.
        Space complexity: O(H). H is a tree height.
        '''
        def dfs(root: TreeNode, curNum: int) -> int:
            if not root:
                return 0
            curNum = (curNum << 1) + root.val
            if not root.left and not root.right:
                return curNum
            return dfs(root.left, curNum) + dfs(root.right, curNum)
        return dfs(root, 0)

    def sumRootToLeaf_MK2(self, root: TreeNode) -> int:
        '''
        Iterative Preorder Traversal.
        Time complexity: O(N). N is a number of nodes.
        Space complexity: O(H). H is a tree height.
        '''
        if not root:
            return 0
        ret = 0
        stack = [(root, 0)]
        while stack:
            node, curNum = stack.pop()
            curNum = (curNum << 1) + node.val
            if not node.left and not node.right:
                ret += curNum
            else:
                if node.right:
                    stack.append((node.right, curNum))
                if node.left:
                    stack.append((node.left, curNum))
        return ret

    def sumRootToLeaf_MK3(self, root: TreeNode) -> int:
        '''
        Morris Preorder Traversal.
        Time complexity: O(N). N is a number of nodes.
        Space complexity: O(1).
        '''
        ret, curNum, steps = 0, 0, 0
        while root:
            if not root.left:
                curNum = (curNum << 1) + root.val
                if not root.right:
                    ret += curNum
                root = root.right
            else:
                succ = root.left
                steps = 1
                while succ.right and succ.right != root:
                    succ = succ.right
                    steps += 1
                if succ.right == root:
                    succ.right = None
                    if not succ.left:
                        ret += curNum
                    for _ in range(steps):
                        curNum >>= 1
                    root = root.right
                else:
                    succ.right = root
                    curNum = (curNum << 1) + root.val
                    root = root.left
        return ret
