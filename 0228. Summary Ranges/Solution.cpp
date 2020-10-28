#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ret;
        for (size_t i = 0; i < nums.size();) {
            size_t j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1] + 1)
                j++;
            ret.emplace_back(to_string(nums[i]));
            if (i != j - 1)
                ret.back() += "->" + to_string(nums[j - 1]);
            i = j;
        }
        return ret;
    }
};
