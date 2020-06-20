#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums);
};

int Solution::minMoves(vector<int> &nums)
{
    int ret = 0, min_item = *min_element(nums.begin(), nums.end());
    for (const int &n : nums)
        ret += n - min_item;
    return ret;
}
