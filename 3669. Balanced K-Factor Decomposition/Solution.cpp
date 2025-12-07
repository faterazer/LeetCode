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
                divisors.push_back(i);
                if (i * i != n)
                    divisors.push_back(n / i);
            }
        }
        ranges::sort(divisors);

        vector<int> path(k), result;
        int min_diff = numeric_limits<int>::max();

        auto dfs = [&](this auto&& self, int i, int target, int start_idx) -> void {
            if (i == k - 1) {
                int diff = target - path[0];
                if (diff < min_diff) {
                    path[i] = target;
                    min_diff = diff;
                    result = path;
                }
                return;
            }

            int max_d = sqrt(target);
            for (size_t idx = start_idx; idx < divisors.size(); ++idx) {
                int d = divisors[idx];
                if (d > max_d || (i > 0 && d - path[0]) >= min_diff)
                    break;
                if (target % d == 0) {
                    path[i] = d;
                    self(i + 1, target / d, idx);
                }
            }
        };

        dfs(0, n, 0);
        return result;
    }
};
