#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<int> res(2, 0);
        for (int x : nums1)
            res[0] += st2.contains(x);
        for (int x : nums2)
            res[1] += st1.contains(x);
        return res;
    }
};
