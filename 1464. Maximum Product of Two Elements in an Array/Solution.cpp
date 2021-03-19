#include <vector>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx1 = 0, mx2 = 0;
        for (const int &x : nums) {
            if (x >= mx1) {
                mx2 = mx1;
                mx1 = x;
            }
            else if (x > mx2) {
                mx2 = x;
            }
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};
