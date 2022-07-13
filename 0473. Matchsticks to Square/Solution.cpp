#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks)
    {
        int all_len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (all_len % 4)
            return false;
        int side_len = all_len / 4;
        for (const int& e : matchsticks)
            if (e > side_len)
                return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(matchsticks, 0, 0, side_len, 4, 0);
    }

private:
    bool dfs(const vector<int>& matchsticks, int idx, int cur, int side_len, int remain, int state)
    {
        if (remain == 0)
            return true;
        if (cur == side_len)
            return dfs(matchsticks, 0, 0, side_len, remain - 1, state);
        for (size_t i = idx; i < matchsticks.size(); ++i) {
            if (state & (1 << i))
                continue;
            if (cur + matchsticks[i] > side_len)
                continue;
            if (dfs(matchsticks, i + 1, cur + matchsticks[i], side_len, remain, state | (1 << i)))
                return true;
            while (i < matchsticks.size() && matchsticks[i] == matchsticks[i + 1])
                ++i;
        }
        return false;
    }
};
