#include <vector>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k)
    {
        int cnt = 0, ans = 0, n = colors.size();
        for (int i = 1; i < n + k - 1; ++i) {
            if (colors[(i - 1) % n] == colors[i % n])
                cnt = 0;
            else
                ++cnt;
        }
        return ans;
    }
};
