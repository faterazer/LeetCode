#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<int> ids(difficulty.size());
        iota(ids.begin(), ids.end(), 0);
        ranges::sort(ids, [&](const int& x, const int& y) {
            return difficulty[x] < difficulty[y];
        });
        ranges::sort(worker);

        int res = 0, max_profit = 0, i = 0, n = ids.size();
        for (int w : worker) {
            while (i < n && difficulty[ids[i]] <= w)
                max_profit = max(max_profit, profit[ids[i++]]);
            res += max_profit;
        }
        return res;
    }
};
