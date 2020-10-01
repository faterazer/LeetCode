#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * Time complexity: O(nlgn).
     * Space complexity: O(1);
     */
    int maximumProduct_MK1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        int m = nums[0] * nums[1] * nums.back();
        return max(m, n);
    }

    /**
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    int maximumProduct_MK2(vector<int> &nums)
    {
        priority_queue<int> minQ;
        priority_queue<int, vector<int>, greater<int>> maxQ;
        for (const int &n : nums) {
            minQ.emplace(n);
            if (minQ.size() > 2)
                minQ.pop();
            maxQ.emplace(n);
            if (maxQ.size() > 3)
                maxQ.pop();
        }
        int max1 = 1, max2 = 1;
        while (!maxQ.empty()) {
            max1 *= maxQ.top();
            max2 = maxQ.top();
            maxQ.pop();
        }
        while (!minQ.empty()) {
            max2 *= minQ.top();
            minQ.pop();
        }
        return max(max1, max2);
    }
};
