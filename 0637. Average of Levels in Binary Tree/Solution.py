from collections import deque
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        queue = deque([root])
        ret = []
        while queue:
            n = len(queue)
            accum = 0.0
            for _ in range(n):
                node = queue.popleft()
                accum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ret.append(accum / n)
        return ret
