#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> arr1(1, nums[0]), arr2(1, nums[1]);
        for (size_t i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back())
                arr1.emplace_back(nums[i]);
            else
                arr2.emplace_back(nums[i]);
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
