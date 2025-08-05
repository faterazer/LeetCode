#include <algorithm>
#include <numeric>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k)
    {
        size_t n = nums1.size();
        vector<size_t> indices(n);
        iota(indices.begin(), indices.end(), 0);
        ranges::sort(indices, {}, [&](size_t i) { return nums1[i]; });

        vector<long long> ans(n, 0);
        priority_queue<int, vector<int>, greater<>> min_heap;
        long long total_sum = 0;
        for (size_t i = 0; i < n; ++i) {
            size_t idx = indices[i];
            if (i > 0 && nums1[indices[i]] == nums1[indices[i - 1]])
                ans[idx] = ans[indices[i - 1]];
            else
                ans[idx] = total_sum;
            min_heap.emplace(nums2[idx]);
            total_sum += nums2[idx];
            if (min_heap.size() > k) {
                total_sum -= min_heap.top();
                min_heap.pop();
            }
        }
        return ans;
    }
};
