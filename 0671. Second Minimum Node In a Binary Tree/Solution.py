from collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        min1, min2 = root.val, -1
        queue = deque([root])
        while queue:
            node = queue.popleft()
            if node.val > min1:
                if min2 == -1:
                    min2 = node.val
                else:
                    min2 = min(min2, node.val)
            if node.left:
                queue.extend([node.left, node.right])
        return min2
