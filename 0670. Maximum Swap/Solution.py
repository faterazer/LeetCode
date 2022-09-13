class Solution:
    def maximumSwap(self, num: int) -> int:
        s = list(str(num))
        max_idx = [0] * 10
        for i, c in enumerate(s):
            max_idx[ord(c) - ord('0')] = i
        for i, c in enumerate(s):
            x, j = ord(c) - ord('0'), 9
            while j > x:
                if max_idx[j] > i:
                    s[i], s[max_idx[j]] = s[max_idx[j]], s[i]
                    return int(''.join(s))
                j -= 1
        return int(''.join(s))
