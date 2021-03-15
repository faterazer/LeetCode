#include <vector>
using namespace std;

class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int sum = 0, res = 1;
        for (const int &x : nums) {
            sum += x;
            if (sum < 1)
                res = max(res, 1 - sum);
        }
        return res;
    }
};
