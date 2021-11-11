#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int res = 0, last = -1;
        for (const int& t : timeSeries) {
            res += t > last ? duration : t - last + duration;
            last = t + duration;
        }
        return res;
    }
};
