#include <algorithm>
#include <cmath>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minDifference(int n, int k)
    {
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.emplace_back(i);
                if (i * i != n)
                    divisors.emplace_back(n / i);
            }
        }
        ranges::sort(divisors);

        int min_diff = numeric_limits<int>::max();
        vector<int> path(k), result;

        auto dfs = [&](this auto&& self, int i, int target) -> void {
            // 只剩最后一个位置，没得选，只能是 target
            if (i == k - 1) {
                if (target - path[0] < min_diff) {
                    min_diff = target - path[0];
                    path[i] = target;
                    result = path;
                }
                return;
            }

            int max_d = sqrt(target);
            for (int d : divisors) {
                if (d > max_d || (i > 0 && d - path[0] >= min_diff))
                    break;

                if (target % d != 0)
                    continue;

                if (i == 0 || d >= path[i - 1]) {
                    path[i] = d;
                    self(i + 1, target / d);
                }
            }
        };

        dfs(0, n);
        return result;
    }
};
