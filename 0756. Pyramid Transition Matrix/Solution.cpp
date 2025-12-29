#include <array>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        array<array<string, 6>, 6> groups;
        for (const string& s : allowed)
            groups[s[0] - 'A'][s[1] - 'A'].push_back(s[2]);
        int n = bottom.size();
        vector<string> pyramid(n);
        for (int i = 0; i < n; ++i)
            pyramid[i].reserve(i + 1);
        pyramid[n - 1] = std::move(bottom);

        unordered_set<string> seen;
        auto dfs = [&](this auto&& self, int i, int j) -> bool {
            if (i < 0)
                return true;

            if (seen.contains(pyramid[i]))
                return false;

            if (j == i + 1) {
                seen.emplace(pyramid[i]);
                return self(i - 1, 0);
            }
            for (char c : groups[pyramid[i + 1][j] - 'A'][pyramid[i + 1][j + 1] - 'A']) {
                pyramid[i].push_back(c);
                if (self(i, j + 1))
                    return true;
                pyramid[i].pop_back();
            }
            return false;
        };
        
        return dfs(n - 2, 0);
    }
};
