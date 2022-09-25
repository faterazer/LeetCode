class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1);
        int overlapWidth = Math.min(ax2, bx2) - Math.max(ax1, bx1);
        int overlapHeight = Math.min(ay2, by2) - Math.max(ay1, by1);
        return area - Math.max(overlapWidth, 0) * Math.max(overlapHeight, 0);
    }
}
