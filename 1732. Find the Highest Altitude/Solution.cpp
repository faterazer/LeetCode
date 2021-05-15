#include <vector>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int res = 0, altitude = 0;
        for (const int &x : gain) {
            altitude += x;
            res = max(res, altitude);
        }
        return res;
    }
};
