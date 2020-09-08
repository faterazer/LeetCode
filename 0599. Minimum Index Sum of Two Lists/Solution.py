from typing import List


class Solution:
    def findRestaurant_MK1(self, list1: List[str], list2: List[str]) -> List[str]:
        indexMap = {s: i for i, s in enumerate(list1)}
        minSum = 2000
        ret = []
        for i, s in enumerate(list2):
            if s not in indexMap:
                continue
            sum = indexMap.get(s) + i
            if sum == minSum:
                ret.append(s)
            elif sum < minSum:
                ret = [s]
                minSum = sum
        return ret

    def findRestaurant_MK2(self, list1: List[str], list2: List[str]) -> List[str]:
        index1 = {s: i for i, s in enumerate(list1)}
        index2 = {s: i for i, s in enumerate(list2)}
        intersection = set(list1) & set(list2)
        sumIndex = {s: index1[s] + index2[s] for s in intersection}
        return [s for s in sumIndex if sumIndex[s] == min(sumIndex.values())]
