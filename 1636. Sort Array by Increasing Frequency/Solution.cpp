#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (const int &x : nums)
            counter[x]++;
        sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
            return counter[a] == counter[b] ? a > b : counter[a] < counter[b];
        });
        return nums;
    }
};
