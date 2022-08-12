from typing import List


class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res = []
        groups = {}
        for i, e in enumerate(groupSizes):
            groups.setdefault(e, []).append(i)
            if len(groups[e]) == e:
                res.append(groups[e])
                groups[e] = []
        return res
