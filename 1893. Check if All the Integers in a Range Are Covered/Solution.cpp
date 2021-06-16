#include <vector>
using namespace std;

class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        int n = right - left + 1, cnt = 0;
        vector<int> range(n, 0);
        for (const vector<int> &r : ranges) {
            if (r[0] < left)
                cnt++;
            else if (r[0] <= right)
                range[r[0] - left]++;
            if (r[1] < left)
                cnt--;
            else if (r[1] < right)
                range[r[1] - left + 1]--;
        }
        for (int i = 0; i < n; i++) {
            cnt += range[i];
            if (!cnt)
                return false;
        }
        return true;
    }
};
