#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + ((right - left) >> 1), count = 0;
            for (const int& e : nums)
                count += (e - 1) / mid;
            if (count > maxOperations)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
