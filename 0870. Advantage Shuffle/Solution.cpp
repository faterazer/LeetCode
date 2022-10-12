#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        vector<vector<int>> tmp;
        for (int i = 0; i < n; i++)
            tmp.push_back({ nums2[i], i });
        sort(nums1.begin(), nums1.end());
        sort(tmp.begin(), tmp.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] < right[0];
        });

        vector<int> res(n);
        int lo = 0, hi = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums1[hi] > tmp[i][0])
                res[tmp[i][1]] = nums1[hi--];
            else
                res[tmp[i][1]] = nums1[lo++];
        }
        return res;
    }
};
