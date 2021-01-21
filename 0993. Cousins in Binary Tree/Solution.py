import collections


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        queue = collections.deque([root])
        while queue:
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                if node.val == x:
                    x = 0
                elif node.val == y:
                    y = 0
                if node.left and node.right and node.left.val in [x, y] and node.right.val in [x, y]:
                    return False
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if not x and not y:
                return True
            elif not x or not y:
                return False
        return False
