from typing import Optional, Tuple

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(root: TreeNode) -> Tuple[int, int]:
            if not root:
                return (0, 0)
            left_rob, left_not_rob = dfs(root.left)
            right_rob, right_not_rob = dfs(root.right)
            return (
                root.val + left_not_rob + right_not_rob,
                max(left_rob, left_not_rob) + max(right_rob, right_not_rob),
            )

        return max(dfs(root))
