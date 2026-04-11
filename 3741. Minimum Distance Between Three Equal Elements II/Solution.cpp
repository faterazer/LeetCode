#include <vector>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums)
    {
        int n = ssize(nums), result = 2 * n;
        vector<int> last1(n + 1, -n), last2(n + 1, -n);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            result = min(result, (i - last2[x]) << 1);
            last2[x] = last1[x];
            last1[x] = i;
        }
        return result == 2 * n ? -1 : result;
    }
};
