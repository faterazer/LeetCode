#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string rankTeams(vector<string>& votes)
    {
        vector<vector<int>> rank(26, vector<int>(26, 0));
        for (const string &vote : votes)
            for (size_t i = 0; i < vote.size(); ++i)
                ++rank[vote[i] - 'A'][i];
        
        string ans = votes[0];
        ranges::sort(ans, [&](char a, char b) {
            return rank[a - 'A'] > rank[b - 'A'] || (rank[a - 'A'] == rank[b - 'A'] && a < b);
        });
        return ans;
    }
};
