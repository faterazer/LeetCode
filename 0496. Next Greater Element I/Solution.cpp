#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> stk;
        unordered_map<int, int> mp;
        for (const int &n : nums2) {
            while (stk.size() && stk.top() < n) {
                mp[stk.top()] = n;
                stk.pop();
            }
            stk.push(n);
        }
        vector<int> ret(nums1.size(), -1);
        for (size_t i = 0; i < nums1.size(); i++)
            if (mp.count(nums1[i]))
                ret[i] = mp[nums1[i]];
        return ret;
    }
};
