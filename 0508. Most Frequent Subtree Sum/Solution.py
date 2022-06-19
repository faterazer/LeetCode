from collections import Counter
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        cnt = Counter()

        def dfs(root: TreeNode) -> int:
            if not root:
                return 0
            res = root.val + dfs(root.left) + dfs(root.right)
            cnt[res] += 1
            return res
        
        dfs(root)
        maxVal = max(cnt.values())
        return [k for k, v in cnt.items() if v == maxVal]
