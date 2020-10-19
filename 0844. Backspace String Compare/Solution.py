class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        i, j = len(S) - 1, len(T) - 1
        skip_s, skip_t = 0, 0
        while i >= 0 or j >= 0:
            while i >= 0 and (S[i] == '#' or skip_s):
                if S[i] == '#':
                    skip_s += 1
                else:
                    skip_s -= 1
                i -= 1
            while j >= 0 and (T[j] == '#' or skip_t):
                if T[j] == '#':
                    skip_t += 1
                else:
                    skip_t -= 1
                j -= 1
            if (i >= 0) != (j >= 0) or i >= 0 and j >= 0 and S[i] != T[j]:
                return False
            i -= 1
            j -= 1
        return True
