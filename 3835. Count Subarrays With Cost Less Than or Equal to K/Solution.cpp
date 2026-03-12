#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k)
    {
        deque<long long> max_queue, min_queue;
        int i = 0, n = nums.size();
        long long result = 0;
        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            while (!max_queue.empty() && max_queue.back() < x)
                max_queue.pop_back();
            max_queue.push_back(x);
            while (!min_queue.empty() && min_queue.back() > x)
                min_queue.pop_back();
            min_queue.push_back(x);

            while ((max_queue.front() - min_queue.front()) * (j - i + 1) > k) {
                if (max_queue.front() == nums[i])
                    max_queue.pop_front();
                if (min_queue.front() == nums[i])
                    min_queue.pop_front();
                ++i;
            }
            result += j - i + 1;
        }
        return result;
    }
};
