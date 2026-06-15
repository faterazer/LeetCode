#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums)
    {
        int lsum = 0, rsum = reduce(nums.begin(), nums.end(), 0);
        vector<int> result;
        result.reserve(nums.size());
        for (int x : nums) {
            rsum -= x;
            result.push_back(abs(lsum - rsum));
            lsum += x;
        }
        return result;
    }
};
