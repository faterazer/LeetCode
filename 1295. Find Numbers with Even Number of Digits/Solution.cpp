#include <vector>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int res = 0;
        for (const int &n : nums)
            if ((n > 9 && n < 100) || (n > 999 && n < 10000) || n > 99999)
                res++;
        return res;
    }
};
