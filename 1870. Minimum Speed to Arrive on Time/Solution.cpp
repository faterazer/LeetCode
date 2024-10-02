#include <algorithm>
#include <cmath>
#include <functional>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        if (n - hour >= 1)
            return -1;

        long long h100 = llround(hour * 100), delta = h100 - (n - 1) * 100;
        int max_dist = ranges::max(dist);
        if (n - hour > 0)
            return max(max_dist, static_cast<int>((dist.back() * 100 - 1) / delta + 1));

        function<bool(int)> check = [&](int v) -> bool {
            long long t = 0;
            for (size_t i = 0; i < dist.size() - 1; ++i)
                t += (dist[i] - 1) / v + 1;
            return (t * v + dist.back()) * 100 <= h100 * v;
        };

        int low = 1, high = (max_dist - 1) / (h100 / (n * 100)) + 1;
        while (low < high) {
            int m = low + ((high - low) >> 1);
            if (check(m))
                high = m;
            else
                low = m + 1;
        }
        return high;
    }
};
