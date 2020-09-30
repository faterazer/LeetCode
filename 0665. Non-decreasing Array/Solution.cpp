#include <vector>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 0;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt += 1;
                if (cnt > 1)
                    return false;
                if (i != 0 && i + 1 != nums.size() - 1 && nums[i] > nums[i + 2] && nums[i + 1] < nums[i - 1])
                    return false;
            }
        }
        return true;
    }
};
