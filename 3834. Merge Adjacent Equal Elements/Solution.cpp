#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums)
    {
        vector<long long> result;
        for (long long x : nums) {
            while (!result.empty() && result.back() == x) {
                result.pop_back();
                x *= 2;
            }
            result.push_back(x);
        }
        return result;
    }
};
