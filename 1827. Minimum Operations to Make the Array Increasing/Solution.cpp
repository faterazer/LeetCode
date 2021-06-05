#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int res = 0, prev = 0;
        for (const int &x : nums) {
            if (x <= prev) {
                res += ++prev - x;
            } else {
                prev = x;
            }
        }
        return res;
    }
};
