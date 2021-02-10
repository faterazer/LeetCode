#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int sum = accumulate(distance.begin(), distance.end(), 0);
        if (start > destination)
            swap(start, destination);
        int d = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        return min(d, sum - d);
    }
};
