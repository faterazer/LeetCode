#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
    {
        int n = ssize(nums);
        vector<int> left(n, -1), right(n, -1);
        unordered_map<int, int> first, last;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            auto it = last.find(x);
            if (it != last.end()) {
                int prev_idx = it->second;
                left[i] = prev_idx;
                right[left[i]] = i;
                it->second = i;
            } else {
                first[x] = i;
                last[x] = i;
            }
        }

        for (const auto& [x, first_idx] : first) {
            int last_idx = last[x];
            left[first_idx] = last_idx - n;
            right[last_idx] = n + first_idx;
        }

        vector<int> result;
        result.reserve(queries.size());
        for (int i : queries) {
            int x = nums[i];
            if (first[x] == last[x])
                result.push_back(-1);
            else
                result.push_back(min(i - left[i], right[i] - i));
        }
        return result;
    }
};
