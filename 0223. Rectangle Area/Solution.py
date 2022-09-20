class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        area = (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1)
        overlap_width = min(ax2, bx2) - max(ax1, bx1)
        overlap_heigt = min(ay2, by2) - max(ay1, by1)
        return area - max(overlap_width, 0) * max(overlap_heigt, 0)
