#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        sort(nums.rbegin(), nums.rend());
        int sum1 = 0, sum2 = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        for (const int &x : nums) {
            res.emplace_back(x);
            sum1 += x;
            sum2 -= x;
            if (sum1 > sum2)
                break;
        }
        return res;
    }
};
