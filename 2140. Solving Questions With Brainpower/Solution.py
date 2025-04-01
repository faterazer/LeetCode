class Solution:
    def mostPoints(self, questions: list[list[int]]) -> int:
        n = len(questions)
        f = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            j = min(i + questions[i][1] + 1, n)
            f[i] = max(f[i + 1], questions[i][0] + f[j])
        return f[0]
