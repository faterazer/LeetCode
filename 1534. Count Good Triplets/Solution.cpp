#include <algorithm>
#include <cmath>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 暴力枚举。
     * 时间复杂度：O(n^3)，n 是 arr 的长度。
     * 空间复杂度：O(1)
     */
    int countGoodTriplets_MK1(vector<int>& arr, int a, int b, int c)
    {
        int res = 0;
        for (size_t i = 0; i < arr.size() - 2; i++) {
            for (size_t j = i + 1; j < arr.size() - 1; j++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (size_t k = j + 1; k < arr.size(); k++)
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            res++;
                }
            }
        }
        return res;
    }

    /**
     * 前缀和。
     * 时间复杂度：O(n(n + U))，n 是 arr 的长度, U = max(arr)。
     * 空间复杂度：O(U)
     */
    int countGoodTriplets_MK2(vector<int>& arr, int a, int b, int c)
    {
        int res = 0, l, r;
        vector<int> preSum(1001, 0);
        for (size_t j = 0; j < arr.size(); j++) {
            for (size_t k = j + 1; k < arr.size(); k++) {
                if (abs(arr[j] - arr[k]) <= b) {
                    l = max(0, max(arr[j] - a, arr[k] - c));
                    r = min(1000, min(arr[j] + a, arr[k] + c));
                    if (l <= r)
                        res += preSum[r] - (l ? preSum[l - 1] : 0);
                }
            }
            for (int k = arr[j]; k <= 1000; k++)
                preSum[k]++;
        }
        return res;
    }

    /**
     * 排序 + 枚举中间下标。
     * 时间复杂度：O(n^2)，n 是 arr 的长度。
     * 空间复杂度：O(n)
     */
    int countGoodTriplets_MK3(vector<int>& arr, int a, int b, int c)
    {
        vector<int> indices(arr.size());
        iota(indices.begin(), indices.end(), 0);
        ranges::sort(indices, {}, [&](int i) { return arr[i]; });

        int ans = 0;
        for (int j : indices) {
            int y = arr[j];
            vector<int> left, right;
            for (int i : indices)
                if (i < j && abs(arr[i] - y) <= a)
                    left.emplace_back(arr[i]);
            for (int k : indices)
                if (k > j && abs(y - arr[k]) <= b)
                    right.emplace_back(arr[k]);

            size_t k1 = 0, k2 = 0;
            for (int x : left) {
                while (k2 < right.size() && right[k2] - x <= c)
                    ++k2;
                while (k1 < right.size() && right[k1] - x < -c)
                    ++k1;
                ans += k2 - k1;
            }
        }
        return ans;
    }
};
