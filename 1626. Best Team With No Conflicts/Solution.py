from typing import List


class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        tree = [0] * (max(ages) + 1)

        def lowbit(x: int) -> int:
            return x & -x

        def update(idx: int, val: int) -> None:
            while idx < len(tree):
                tree[idx] = max(tree[idx], val)
                idx += lowbit(idx)

        def query(idx: int) -> int:
            res = 0
            while idx > 0:
                res = max(res, tree[idx])
                idx -= lowbit(idx)
            return res

        for score, age in sorted(zip(scores, ages)):
            update(age, query(age) + score)
        return query(max(ages))
