#include <algorithm>
#include <numeric>
#include <queue>
#include <ranges>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    // Time complexity: O(n log k), where n is the size of nums.
    // Space complexity: O(k), for the min-heap and the unordered_multiset.
    vector<int> maxSubsequence_MK1(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int x : nums) {
            min_heap.push(x);
            if (min_heap.size() > k)
                min_heap.pop();
        }

        unordered_multiset<int> ust;
        while (!min_heap.empty()) {
            ust.emplace(min_heap.top());
            min_heap.pop();
        }

        vector<int> ans;
        for (int x : nums) {
            if (ust.contains(x)) {
                ans.emplace_back(x);
                ust.erase(ust.find(x));
            }
        }
        return ans;
    }

    // Time Complexity: O(n log n)
    // Space Complexity: O(n)
    vector<int> maxSubsequence_MK2(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        ranges::nth_element(ids, ids.begin() + k, {}, [&](int i) { return -nums[i]; });

        vector<int> flags(n, 0);
        for (int i = 0; i < k; ++i)
            flags[ids[i]] = 1;

        ids.resize(k);
        int j = 0;
        for (int i = 0; i < n; ++i)
            if (flags[i])
                ids[j++] = nums[i];
        return ids;
    }
};
