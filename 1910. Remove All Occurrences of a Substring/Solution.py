class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n = len(part)
        next = [0] * n
        j = 0
        for i in range(1, n):
            while j > 0 and part[i] != part[j]:
                j = next[j - 1]
            if part[i] == part[j]:
                j += 1
            next[i] = j

        ans = []
        next_cache = [0]
        for c in s:
            ans.append(c)
            j = next_cache[-1]
            while j > 0 and c != part[j]:
                j = next[j - 1]
            if c == part[j]:
                j += 1
            next_cache.append(j)
            if j == n:
                ans = ans[:-n]
                next_cache = next_cache[:-n]
        return "".join(ans)
