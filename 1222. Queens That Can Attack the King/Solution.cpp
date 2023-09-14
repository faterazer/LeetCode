#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
    {
        unordered_set<int> queens_set;
        for (const vector<int>& queen : queens)
            queens_set.emplace(queen[0] * 10 + queen[1]);

        vector<vector<int>> res;
        for (auto& d : directions) {
            for (int x = king[0] + d[0], y = king[1] + d[1]; 0 <= x && x < 8 && 0 <= y && y <= 8; x += d[0], y += d[1])
                if (queens_set.count(x * 10 + y)) {
                    res.push_back({x, y});
                    break;
                }
        }
        return res;
    }

private:
    const int directions[8][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { -1, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 } };
};
