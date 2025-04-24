from collections import defaultdict


class Solution:
    def countCompleteSubarrays(self, nums: list[int]) -> int:
        n = len(set(nums))
        cnt = defaultdict(int)
        ans = i = 0
        for x in nums:
            cnt[x] += 1
            while len(cnt) == n:
                cnt[nums[i]] -= 1
                if cnt[nums[i]] == 0:
                    cnt.pop(nums[i])
                i += 1
            ans += i
        return ans
