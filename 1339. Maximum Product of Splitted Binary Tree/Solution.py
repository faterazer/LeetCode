from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        tmp = [0, 0]

        def treeSum(root: TreeNode) -> int:
            if not root:
                return 0
            cur_sum = root.val + treeSum(root.left) + treeSum(root.right)
            if abs(2 * cur_sum - tmp[0]) < abs(2 * tmp[1] - tmp[0]):
                tmp[1] = cur_sum
            return cur_sum

        tmp[0] = treeSum(root)
        treeSum(root)
        total, best = tmp
        return best * (total - best) % (10 ** 9 + 7)
