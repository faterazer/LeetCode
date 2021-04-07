#include <vector>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int cnt = 0;
        for (const int &x : arr) {
            cnt = x & 1 ? cnt + 1 : 0;
            if (cnt == 3)
                return true;
        }
        return false;
    }
};
