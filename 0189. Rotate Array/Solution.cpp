#include <algorithm>
#include <vector>
using namespace std;


class Solution
{
public:
    void rotate_MK1(vector<int> &nums, int k);
    void rotate_MK2(vector<int> &nums, int k);
};

void Solution::rotate_MK1(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void Solution::rotate_MK2(vector<int> &nums, int k)
{
    k %= nums.size();
    size_t count = 0;
    for (int start = 0; count < nums.size(); start++) {
        int curr = start;
        int prev = nums[start];
        do {
            int next = (curr + k) % nums.size();
            int tmp = nums[next];
            nums[next] = prev;
            prev = tmp;
            curr = next;
            count++;
        } while(start != curr);
    }
}
