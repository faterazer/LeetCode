class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        cnt = [0] * 27
        for c in s:
            cnt[ord(c) - ord("a")] += 1
        P = 10 ** 9 + 7

        for _ in range(t):
            for i in range(26, 0, -1):
                cnt[i] = cnt[i - 1]
            cnt[0] = cnt[26]
            cnt[1] = (cnt[1] + cnt[26]) % P
            cnt[26] = 0

        return sum(cnt) % P
