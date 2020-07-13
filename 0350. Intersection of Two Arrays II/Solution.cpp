#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersect_MK1(vector<int> &nums1, vector<int> &nums2);  // 哈希映射
    vector<int> intersect_MK2(vector<int> &nums1, vector<int> &nums2);  // 排序
    vector<int> intersect_MK3(vector<int> &nums1, vector<int> &nums2);  // STL - set_intersection
    vector<int> intersect_MK4(vector<int> &nums1, vector<int> &nums2);  // STL - multiset
};

vector<int> Solution::intersect_MK1(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return intersect_MK1(nums2, nums1);
    
    unordered_map<int, int> hash_map;
    for (const int &n : nums1)
        hash_map[n]++;
    vector<int> ret;
    for (const int &n : nums2) {
        if (hash_map.count(n) && hash_map[n] > 0) {
            ret.emplace_back(n);
            hash_map[n]--;
        }
    }
    return ret;
}

vector<int> Solution::intersect_MK2(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ret;
    for (size_t i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
        if (nums1[i] == nums2[j]) {
            ret.emplace_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return ret;
}

vector<int> Solution::intersect_MK3(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ret;
    set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), inserter(ret, ret.begin()));
    return ret;
}

vector<int> Solution::intersect_MK4(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return intersect_MK4(nums2, nums1);

    unordered_multiset<int> hash_set;
    vector<int> ret;
    for (const int &n : nums1)
        hash_set.insert(n);
    for (const int &n : nums2) {
        if (hash_set.count(n)) {
            ret.emplace_back(n);
            hash_set.erase(hash_set.find(n));
        }
    }
    return ret;
}
