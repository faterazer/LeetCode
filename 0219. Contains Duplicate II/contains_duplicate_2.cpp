#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate_MK1(vector<int> &nums, int k); // use map
    bool containsNearbyDuplicate_MK2(vector<int> &nums, int k); // use set
};

bool Solution::containsNearbyDuplicate_MK2(vector<int> &nums, int k)
{
    unordered_map<int, int> memo;
    for (size_t i = 0; i < nums.size(); i++) {
        if (memo.find(nums[i]) == memo.end() || i - memo[nums[i]] > k)
            memo[nums[i]] = i;
        else
            return true;
    }
    return false;
}

bool Solution::containsNearbyDuplicate_MK2(vector<int> &nums, int k)
{
    unordered_set<int> memo;
    for (size_t i = 0; i < nums.size(); i++) {
        if (i > k)
            memo.erase(nums[i - k - 1]);
        if (memo.find(nums[i]) != memo.end())
            return true;
        memo.insert(nums[i]);
    }
    return false;
}
