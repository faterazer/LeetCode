#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        unordered_map<int, int> ball2color, color2cnt;
        vector<int> ans;
        ans.reserve(queries.size());
        for (const vector<int> &query : queries) {
            int ball = query[0], color = query[1];
            int old_color = ball2color[ball];
            if (color2cnt.contains(old_color) && --color2cnt[old_color] == 0)
                color2cnt.erase(old_color);
            ball2color[ball] = color;
            ++color2cnt[color];
            ans.emplace_back(color2cnt.size());
        }
        return ans;
    }
};
