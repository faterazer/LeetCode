#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maximum = 0, count = 0;
        for (const int &n : nums) {
            if (n)
                count++;
            else {
                maximum = max(maximum, count);
                count = 0;
            }
        }
        return max(maximum, count);
    }
};
