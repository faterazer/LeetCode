from collections import deque
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        ret = []
        if not root:
            return ret
        
        queue = deque()
        queue.append(root)
        while queue:
            n, node = len(queue), None
            for _ in range(n):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ret.append(node.val)
        return ret
