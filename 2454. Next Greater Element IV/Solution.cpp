#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> res(n, -1), stk1, stk2;
        for (int i = 0; i < n; i++) {
            while (!stk2.empty() && nums[stk2.back()] < nums[i]) {
                res[stk2.back()] = nums[i];
                stk2.pop_back();
            }
            int j = stk1.size();
            while (j && nums[stk1[j - 1]] < nums[i])
                j--;
            stk2.insert(stk2.end(), stk1.begin() + j, stk1.end());
            stk1.resize(j);
            stk1.emplace_back(i);
        }
        return res;
    }
};
