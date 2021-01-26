#include <vector>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int gap = k;
        for (const int &x : nums) {
            if (x) {
                if (gap < k)
                    return false;
                gap = 0;
            }
            else
                gap++;
        }
        return true;
    }
};
