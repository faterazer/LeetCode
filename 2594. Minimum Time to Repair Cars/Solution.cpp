#include <algorithm>
#include <cmath>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars)
    {
        long long left = 0, right = 1LL * ranges::min(ranks) * cars * cars;
        while (left < right) {
            long long mid = left + ((right - left) >> 1);

            long long cnt = 0;
            for (int r : ranks)
                cnt += sqrt(mid / r);

            if (cnt >= cars)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
