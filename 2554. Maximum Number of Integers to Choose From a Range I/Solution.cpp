#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        unordered_set<int> ust(banned.begin(), banned.end());
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i > maxSum)
                break;
            if (!ust.contains(i)) {
                maxSum -= i;
                ++ans;
            }
        }
        return ans;
    }
};
