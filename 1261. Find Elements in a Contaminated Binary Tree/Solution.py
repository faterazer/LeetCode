from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        self.root = root

    def find(self, target: int) -> bool:
        target += 1
        cur = self.root
        for i in range(target.bit_length() - 2, -1, -1):
            bit = (target >> i) & 1
            cur = cur.right if bit else cur.left
            if cur is None:
                return False
        return True


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
