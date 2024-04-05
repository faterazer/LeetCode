#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int res = 0, left = 0, right = height.size() - 1, pre_max = 0, suf_max = 0;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            res += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
        }
        return res;
    }
};
