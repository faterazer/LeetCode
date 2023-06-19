class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        cnt = {}
        left = res = 0
        for right in range(len(s)):
            cnt[s[right]] = right
            while len(cnt) > 2:
                if cnt[s[left]] == left:
                    cnt.pop(s[left])
                left += 1
            res = max(res, right - left + 1)
        return res
