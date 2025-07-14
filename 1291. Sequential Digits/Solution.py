class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        ans = []
        for i in range(1, 10):
            x = i
            for j in range(i + 1, 10):
                x = x * 10 + j
                if low <= x <= high:
                    ans.append(x)
        return sorted(ans)
