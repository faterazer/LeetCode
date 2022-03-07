#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> max_queue;
        for (int i = 0; i < k; ++i) {
            while (!max_queue.empty() && max_queue.back() < nums[i])
                max_queue.pop_back();
            max_queue.emplace_back(nums[i]);
        }
        vector<int> res { max_queue.front() };
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i - k] == max_queue.front())
                max_queue.pop_front();
            while (!max_queue.empty() && max_queue.back() < nums[i])
                max_queue.pop_back();
            max_queue.emplace_back(nums[i]);
            res.emplace_back(max_queue.front());
        }
        return res;
    }
};
