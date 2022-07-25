from collections import deque
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class CBTInserter:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.candidates = deque([root])
        while self.candidates[0].right:
            node = self.candidates.popleft()
            if node.left:
                self.candidates.append(node.left)
            if node.right:
                self.candidates.append(node.right)
        if self.candidates[0].left:
            self.candidates.append(self.candidates[0].left)

    def insert(self, val: int) -> int:
        node = TreeNode(val)
        self.candidates.append(node)
        front = self.candidates[0]
        if not front.left:
            front.left = node
        else:
            front.right = node
            self.candidates.popleft()
        return front.val

    def get_root(self) -> Optional[TreeNode]:
        return self.root

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()
