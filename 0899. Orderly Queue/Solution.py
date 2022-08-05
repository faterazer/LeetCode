class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k > 1:
            return ''.join(sorted(s))
        else:
            n = len(s)
            offset, i, j = 0, 0, 1
            while offset < n and i < n and j < n:
                if s[(i + offset) % n] == s[(j + offset) % n]:
                    offset += 1
                else:
                    if s[(i + offset) % n] > s[(j + offset) % n]:
                        i = i + offset + 1
                    else:
                        j = j + offset + 1
                    if i == j:
                        i += 1
                    offset = 0
            i = min(i, j)
            return s[i:] + s[:i]
