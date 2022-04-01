#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m)
    {
        int left = 0, right = 0, mid;
        for (const int& e : nums) {
            left = max(left, e);
            right += e;
        }
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (valid(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }

private:
    bool valid(vector<int> &nums, int m, int sum_limit) {
        int sum = 0, cnt = 1;
        for (const int &e : nums) {
            if (sum + e <= sum_limit) {
                sum += e;
            } else {
                sum = e;
                cnt += 1;
            }
        }
        return cnt <= m;
    }
};
