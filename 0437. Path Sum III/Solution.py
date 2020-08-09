from typing import Dict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        path_sum = {0: 1}
        return self.dfs(root, sum, path_sum, 0)

    def dfs(self, root: TreeNode, sum: int, path_sum: Dict[int, int], cur_sum: int) -> int:
        if not root:
            return 0

        cur_sum += root.val
        res = path_sum.get(cur_sum - sum, 0)
        path_sum[cur_sum] = path_sum.get(cur_sum, 0) + 1
        res += self.dfs(root.left, sum, path_sum, cur_sum) + \
            self.dfs(root.right, sum, path_sum, cur_sum)
        path_sum[cur_sum] -= 1
        return res
