class Solution:
    def maxDistance(self, arrays: list[list[int]]) -> int:
        ans, min_val, max_val = 0, arrays[0][0], arrays[0][-1]
        for i in range(1, len(arrays)):
            ans = max(ans, abs(arrays[i][-1] - min_val), abs(max_val - arrays[i][0]))
            min_val = min(min_val, arrays[i][0])
            max_val = max(max_val, arrays[i][-1])
        return ans
