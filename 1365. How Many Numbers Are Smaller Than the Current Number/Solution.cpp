#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> hashMap(101, 0);
        for (const int &num : nums)
            hashMap[num] += 1;
        for (size_t i = 1; i < hashMap.size(); i++)
            hashMap[i] += hashMap[i - 1];
        vector<int> ret(nums.size(), 0);
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i])
                ret[i] = hashMap[nums[i] - 1];
        return ret;
    }
};
