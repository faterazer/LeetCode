#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int seen[101] = {0};
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (seen[nums[i]])
                return (i + 3) / 3;
            seen[nums[i]] = 1;
        }
        return 0;
    }
};
