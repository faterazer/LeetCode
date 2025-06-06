class Solution:
    def robotWithString(self, s: str) -> str:
        n = len(s)
        suffix_min = ["z"] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix_min[i] = min(suffix_min[i + 1], s[i])

        ans = []
        stack = []
        for i, c in enumerate(s):
            stack.append(c)
            while stack and stack[-1] <= suffix_min[i + 1]:
                ans.append(stack.pop())
        return "".join(ans)
