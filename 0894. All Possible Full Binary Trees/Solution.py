from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        self.f = [[] for _ in range(11)]
        self.f[1].append(TreeNode(0))
        for i in range(2, 11):
            for j in range(1, i):
                for left in self.f[j]:
                    for right in self.f[i - j]:
                        self.f[i].append(TreeNode(0, left, right))

    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        return self.f[(n + 1) // 2]
