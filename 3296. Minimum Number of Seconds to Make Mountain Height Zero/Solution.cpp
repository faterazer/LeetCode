#include <algorithm>
#include <cmath>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds_MK1(int mountainHeight, vector<int>& workerTimes)
    {
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        for (int x : workerTimes)
            pq.emplace(x, 2, x);
        for (; mountainHeight > 1; --mountainHeight) {
            auto [next_t, n, wt] = pq.top();
            pq.pop();
            pq.emplace(next_t + 1LL * n * wt, n + 1, wt);
        }
        return get<0>(pq.top());
    }

    long long minNumberOfSeconds_MK2(int mountainHeight, vector<int>& workerTimes)
    {
        auto check = [&](long long m) -> bool {
            int s = 0;
            for (int t : workerTimes) {
                s += (static_cast<int>(sqrt(8 * m / t + 1)) - 1) / 2;
                if (s >= mountainHeight)
                    return true;
            }
            return false;
        };

        int max_t = ranges::max(workerTimes);
        int h = (mountainHeight - 1) / workerTimes.size() + 1;
        long long left = 0, right = 1LL * max_t * h * (h + 1) / 2;
        while (left < right) {
            long long mid = left + ((right - left) >> 1);
            if (check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};
