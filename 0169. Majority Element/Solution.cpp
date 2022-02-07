#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums);
};

int Solution::majorityElement(vector<int> &nums)
{
    int major, count = 0;
    for (const auto &num : nums) {
        if (!count)
            major = num;
        if (num == major)
            count++;
        else
            count--;
    }
    return major;
}
