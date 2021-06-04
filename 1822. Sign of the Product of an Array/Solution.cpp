#include <vector>
using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int res = 1;
        for (const int &x : nums) {
            if (x < 0)
                res *= -1;
            else if (!x)
                return 0;
        }
        return res;
    }
};
