#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors)
    {
        int i = 0, j = colors.size() - 1, n = colors.size();
        while (i < n && colors[i] == colors.back())
            ++i;
        while (j >= 0 && colors[j] == colors.front())
            --j;
        return max(n - i - 1, j);
    }
};
