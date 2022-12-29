#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        unordered_map<int, int> count;
        for (const int& e : nums1)
            count[e] = 1;
        for (const int& e : nums2)
            count[e] |= 2;
        for (const int& e : nums3)
            count[e] |= 4;
        vector<int> res;
        for (const auto& [k, v] : count)
            if (v & (v - 1))
                res.emplace_back(k);
        return res;
    }
};
