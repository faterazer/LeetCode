#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal)
    {
        long long need = abs(accumulate(nums.begin(), nums.end(), 0L) - goal);
        return need / limit + (need % limit != 0);
    }
};
