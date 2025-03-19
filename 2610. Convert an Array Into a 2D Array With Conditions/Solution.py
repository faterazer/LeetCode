from collections import Counter


class Solution:
    def findMatrix(self, nums: list[int]) -> list[list[int]]:
        cnt = Counter(nums)
        ans = []
        while cnt:
            ans.append(list(cnt.keys()))
            for k in ans[-1]:
                cnt[k] -= 1
                if cnt[k] == 0:
                    cnt.pop(k)
        return ans
