class Solution:
    def hasIncreasingSubarrays(self, nums: list[int], k: int) -> bool:
        consecutive_k_runs = 0
        n, i = len(nums), 0
        while i < n:
            j = i + 1
            while j < n and nums[j] > nums[j - 1]:
                j += 1
            if j - i >= 2 * k:
                return True
            consecutive_k_runs = consecutive_k_runs + 1 if j - i >= k else 0
            if consecutive_k_runs >= 2:
                return True
            i = j
        return False
