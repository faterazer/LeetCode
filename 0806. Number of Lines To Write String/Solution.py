from typing import List


class Solution:
    def numberOfLines(self, widths: List[int], S: str) -> List[int]:
        lines, width = 1, 0
        for ch in S:
            if width + widths[ord(ch) - ord('a')] > 100:
                width = 0
                lines += 1
            width += widths[ord(ch) - ord('a')]
        return [lines, width]
