#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        int n = scores.size();
        pair<int, int> players[n];
        for (int i = 0; i < scores.size(); i++)
            players[i] = { scores[i], ages[i] };
        sort(players, players + n);

        f = vector<int>(max_age + 1, 0);
        for (const auto& [score, age] : players)
            update(age, query(age) + score);
        return query(max_age);
    }

private:
    void update(int idx, int val)
    {
        for (; idx <= max_age; idx += idx & -idx)
            f[idx] = max(f[idx], val);
    }

    int query(int idx)
    {
        int res = 0;
        for (; idx; idx &= idx - 1)
            res = max(res, f[idx]);
        return res;
    }

    static constexpr int max_age = 1000;
    vector<int> f;
};
