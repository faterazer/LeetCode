from typing import List


class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.append(" ")
        i = j = 0
        while j < len(s):
            if s[j] == " ":
                s[i:j] = s[i:j][::-1]
                i = j + 1
            j += 1
        s.pop()
        s[:] = s[::-1]
