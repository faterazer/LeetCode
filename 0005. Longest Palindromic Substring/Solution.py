from typing import Tuple


class Solution:
    def expandAroundCenter(self, s: str, left: int, right: int) -> Tuple[int, int]:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left + 1, right - 1

    def longestPalindrome_MK1(self, s: str) -> str:
        '''
        Time complexity: O(n^2)
        Space complexity: O(1)
        '''
        beg = end = 0
        for i in range(len(s)):
            left, right = self.expandAroundCenter(s, i, i)
            if right - left > end - beg:
                beg, end = left, right
            left, right = self.expandAroundCenter(s, i, i + 1)
            if right - left > end - beg:
                beg, end = left, right
        return s[beg:end+1]

    def longestPalindrome_MK2(self, s: str) -> str:
        '''
        Manacher
        Time complexity: O(n)
        Space complexity: O(n)
        '''
        ss = ['#'] * (2 * len(s) + 1)
        for i, c in enumerate(s):
            ss[2 * i + 1] = c
        ss = ''.join(ss)

        p = [0] * len(ss)
        center, max_right = 0, 0
        beg = end = 0
        for i in range(len(ss)):
            if i >= max_right:
                center = i
                max_right = self.expandAroundCenter(ss, i, i)[1]
                p[i] = max_right - center
            else:
                p[i] = min(p[2 * center - i], max_right - i)
                right = self.expandAroundCenter(ss, i - p[i], i + p[i])[1]
                if right > max_right:
                    center = i
                    max_right = right
                p[i] = right - i
            if p[i] * 2 > end - beg:
                beg, end = i - p[i], i + p[i]
        return ''.join(c for c in ss[beg:end + 1] if c != '#')
