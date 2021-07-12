#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        nums.insert(nums.begin(), nums.begin(), nums.end());
        return nums;
    }
};
