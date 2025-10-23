#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 暴力法，适合 k 值较小的情况
    int xorAfterQueries_MK1(vector<int>& nums, vector<vector<int>>& queries)
    {
        constexpr int MOD = 1e9 + 7;
        for (const vector<int>& query : queries) {
            int l = query[0], r = query[1], k = query[2], v = query[3];
            for (int i = l; i <= r; i += k)
                nums[i] = (nums[i] * 1LL * v) % MOD;
        }
        return reduce(nums.begin(), nums.end(), 0, bit_xor());
    }

    // 商分数组，适合 k 值较大的情况
    int xorAfterQueries_MK2(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        unordered_map<int, vector<tuple<int, int, int>>> groups; // k -> (l, r, v)
        for (const vector<int>& query : queries)
            groups[query[2]].emplace_back(query[0], query[1], query[3]);
        
        for (const auto& [k, group] : groups) {
            unordered_map<int, vector<tuple<int, int, int>>> buckets; // l % k -> (l, r, v)
            for (const auto& [l, r, v] : group)
                buckets[l % k].emplace_back(l, r, v);
            
            for (const auto& [start, bucket] : buckets) {
                int m = (n - 1 - start) / k + 1;
                vector<int> diff(m + 1, 1);
                for (const auto& [l, r, v] : bucket) {
                    diff[l / k] = diff[l / k] * 1LL * v % MOD;
                    int end_idx = (r - start) / k + 1;
                    diff[end_idx] = diff[end_idx] * 1LL * pow(v, MOD - 2) % MOD;
                }

                int mul_d = 1;
                for (int i = 0; i < m; ++i) {
                    mul_d = mul_d * 1LL * diff[i] % MOD;
                    int j = start + i * k;
                    nums[j] = nums[j] * 1LL * mul_d % MOD;
                }
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
