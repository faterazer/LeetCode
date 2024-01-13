class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord("a")] += 1

        ans = []
        i, j = 25, 24
        while i >= 0:
            if cnt[i] == 0:
                i -= 1
            elif cnt[i] <= repeatLimit:
                ans.append(chr(i + ord("a")) * cnt[i])
                i -= 1
            else:
                ans.append(chr(i + ord("a")) * repeatLimit)
                cnt[i] -= repeatLimit
                if j >= i:
                    j = i - 1
                while j >= 0 and cnt[j] == 0:
                    j -= 1
                if j < 0:
                    break
                ans.append(chr(j + ord("a")))
                cnt[j] -= 1
        return "".join(ans)
