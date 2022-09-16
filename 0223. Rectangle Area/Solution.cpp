#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int area = (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1);
        int overlap_width = min(ax2, bx2) - max(ax1, bx1), overlap_height = min(ay2, by2) - max(ay1, by1);
        int overlap_area = max(overlap_width, 0) * max(overlap_height, 0);
        return area - overlap_area;
    }
};
