from collections import defaultdict


class Solution:
    def beautifulSubarrays(self, nums: list[int]) -> int:
        ans = prefix_xor = 0
        cnt = defaultdict(int)
        cnt[0] = 1
        for x in nums:
            prefix_xor ^= x
            ans += cnt[prefix_xor]
            cnt[prefix_xor] += 1
        return ans
