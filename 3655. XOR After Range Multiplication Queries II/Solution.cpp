#include <cmath>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int B = ceil(sqrt(queries.size()));
        map<pair<int, int>, vector<tuple<int, int, int>>> groups;
        for (const vector<int>& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < B)
                groups[{ k, l % k }].emplace_back(l, r, v);
            else {
                for (int i = l; i <= r; i += k)
                    nums[i] = 1LL * nums[i] * v % MOD;
            }
        }

        int n = nums.size();
        for (auto& [key, group] : groups) {
            int k = key.first, start = key.second;
            int m = (n - start - 1) / k + 1;
            vector<int> diff(m + 1, 1);
            for (auto [l, r, v] : group) {
                int beg = (l - start) / k, end = (r - start) / k + 1;
                diff[beg] = diff[beg] * 1LL * v % MOD;
                diff[end] = diff[end] * 1LL * pow(v, MOD - 2) % MOD;
            }

            long long mul_d = 1;
            for (int i = 0; i < m; ++i) {
                mul_d = mul_d * diff[i] % MOD;
                int j = start + i * k;
                nums[j] = nums[j] * mul_d % MOD;
            }
        }
        return reduce(nums.begin(), nums.end(), 0, bit_xor());
    }

private:
    long long pow(long long x, int n)
    {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2)
                res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }

    const int MOD = 1e9 + 7;
};
