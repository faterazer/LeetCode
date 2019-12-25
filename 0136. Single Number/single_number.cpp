#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums);
};

int Solution::singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (const auto &num : nums)
        ans ^= num;
    return ans;
}
