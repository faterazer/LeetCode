from typing import List


class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        max_val, total = max(milestones), sum(milestones)
        return 2 * (total - max_val) + 1 if 2 * max_val > total else total
