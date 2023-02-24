#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_set<int> ust(nums.begin(), nums.end());
        return ust.size() - ust.count(0);
    }
};
