class Solution:
    def solveQueries(self, nums: list[int], queries: list[int]) -> list[int]:
        n = len(nums)
        left, right = [-1] * n, [-1] * n
        first, last = {}, {}
        for i, x in enumerate(nums):
            if x in last:
                left[i] = last[x]
                right[left[i]] = i
                last[x] = i
            else:
                first[x] = last[x] = i

        for x, first_idx in first.items():
            last_idx = last[x]
            left[first_idx] = last_idx - n
            right[last_idx] = n + first_idx

        result = [0] * len(queries)
        for i, q in enumerate(queries):
            x = nums[q]
            if first[x] == last[x]:
                result[i] = -1
            else:
                result[i] = min(q - left[q], right[q] - q)
        return result
