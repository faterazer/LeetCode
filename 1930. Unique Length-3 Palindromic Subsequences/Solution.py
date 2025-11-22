class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        ord_a = ord("a")
        n = len(s)

        suf_cnt = [0] * 26
        suf_mask = 0
        for i in range(1, n):
            k = ord(s[i]) - ord_a
            suf_cnt[k] += 1
            suf_mask |= 1 << k

        pre_mask = 0
        letter_masks = [0] * 26
        for i in range(1, n - 1):
            mid = ord(s[i]) - ord_a
            suf_cnt[mid] -= 1
            if suf_cnt[mid] == 0:
                suf_mask ^= 1 << mid
            pre_mask |= 1 << (ord(s[i - 1]) - ord_a)
            letter_masks[mid] |= pre_mask & suf_mask
        return sum(mask.bit_count() for mask in letter_masks)
