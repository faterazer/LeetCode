#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> f(days.size() + 1, 0);
        int j = 0, k = 0;
        for (size_t i = 0; i < days.size(); ++i) {
            while (days[i] - days[j] >= 7)
                ++j;
            while (days[i] - days[k] >= 30)
                ++k;
            f[i + 1] = ranges::min({ f[i] + costs[0], f[j] + costs[1], f[k] + costs[2] });
        }
        return f.back();
    }
};
