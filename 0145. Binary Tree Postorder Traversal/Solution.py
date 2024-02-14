from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res

        def getSuccessor(node: TreeNode) -> TreeNode:
            succ = node.left
            while succ.right and succ.right != node:
                succ = succ.right
            return succ

        def addPath(node: TreeNode) -> None:
            tmp = []
            while node:
                tmp.append(node.val)
                node = node.right
            res.extend(tmp[::-1])

        node = root
        while node:
            if not node.left:
                node = node.right
            else:
                succ = getSuccessor(node)
                if succ.right != node:
                    succ.right = node
                    node = node.left
                else:
                    succ.right = None
                    addPath(node.left)
                    node = node.right
        addPath(root)
        return res
