from collections import defaultdict


class Solution:
    def countGood(self, nums: list[int], k: int) -> int:
        cnt = defaultdict(int)
        ans = good_cnt = left = 0
        for x in nums:
            good_cnt += cnt[x]
            cnt[x] += 1
            while good_cnt >= k:
                cnt[nums[left]] -= 1
                good_cnt -= cnt[nums[left]]
                left += 1
            ans += left
        return ans
