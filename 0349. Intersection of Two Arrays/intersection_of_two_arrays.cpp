#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2);
};

vector<int> Solution::intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ret;
    unordered_set<int> hash_set(nums1.begin(), nums1.end());
    for (const int &n : unordered_set<int>(nums2.begin(), nums2.end()))
        if (hash_set.count(n))
            ret.emplace_back(n);
    return ret;
}
