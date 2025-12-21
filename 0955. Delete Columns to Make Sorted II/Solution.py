class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        n, m = len(strs), len(strs[0])
        ambiguous_rows = list(range(n - 1))

        result = 0
        for j in range(m):
            for i in ambiguous_rows:
                if strs[i][j] > strs[i + 1][j]:
                    result += 1
                    break
            else:
                size = 0
                for i in ambiguous_rows:
                    if strs[i][j] == strs[i + 1][j]:
                        ambiguous_rows[size] = i
                        size += 1
                del ambiguous_rows[size:]
            if not ambiguous_rows:
                break
        return result
