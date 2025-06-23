class Solution:
    def maxDistance(self, colors: list[int]) -> int:
        i, j, n = 0, len(colors) - 1, len(colors)
        while i < n and colors[i] == colors[-1]:
            i += 1
        while j >= 0 and colors[j] == colors[0]:
            j -= 1
        return max(n - i - 1, j)
