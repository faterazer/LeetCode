#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // Time complexity: O(nlgn)
    int specialArray_MK1(vector<int> &nums)
    {
        int n = nums.size(), X;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            X = n - i;
            if (nums.end() - lower_bound(nums.begin(), nums.end(), X) == X)
                return X;
        }
        return -1;
    }

    // Time complexity: (n)
    int specialArray_MK2(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0;
        vector<int> counter(n + 1, 0);
        for (const int &x : nums)
            counter[min(x, n)]++;
        for (int i = n; i > 0; i--) {
            cnt += counter[i];
            if (cnt == i)
                return i;
        }
        return -1;
    }
};
