#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                res = max(res, (r - l) * height[l]);
                l += 1;
            } else {
                res = max(res, (r - l) * height[r]);
                r -= 1;
            }
        }
        return res;
    }
};
