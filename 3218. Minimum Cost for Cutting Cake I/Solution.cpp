#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut)
    {
        ranges::sort(horizontalCut);
        ranges::sort(verticalCut);
        int i = 0, j = 0, ans = 0;
        while (i < m - 1 || j < n - 1) {
            if (i == m - 1)
                ans += verticalCut[j++];
            else if (j == n - 1)
                ans += horizontalCut[i++];
            else if (horizontalCut[i] < verticalCut[j])
                ans += horizontalCut[i++] * (n - j);
            else
                ans += verticalCut[j++] * (m - i);
        }
        return ans;
    }
};
