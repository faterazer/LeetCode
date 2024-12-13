#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        auto comp = [&](int a, int b) { return nums[a] == nums[b] ? a > b : nums[a] > nums[b]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (size_t i = 0; i < nums.size(); ++i)
            pq.emplace(i);

        while (k--) {
            int idx = pq.top();
            pq.pop();
            nums[idx] *= multiplier;
            pq.emplace(idx);
        }
        return nums;
    }
};
