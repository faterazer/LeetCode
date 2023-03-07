#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips)
    {
        long long lo = *min_element(time.begin(), time.end()), hi = lo * totalTrips;
        while (lo < hi) {
            long long mid = lo + ((hi - lo) >> 1);
            long long trips = 0;
            for (const int& t : time)
                trips += mid / t;
            if (trips < totalTrips)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
