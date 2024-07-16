#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        unordered_map<string, vector<int>> email2ids;
        for (size_t i = 0; i < accounts.size(); i++)
            for (size_t j = 1; j < accounts[i].size(); j++)
                email2ids[accounts[i][j]].emplace_back(i);

        vector<int> visited(accounts.size(), 0);
        unordered_set<string> email_set;

        function<void(int)> dfs = [&](int x) -> void {
            visited[x] = 1;
            for (int j = 1; j < accounts[x].size(); j++) {
                if (email_set.contains(accounts[x][j]))
                    continue;

                email_set.emplace(accounts[x][j]);
                for (int k : email2ids[accounts[x][j]])
                    if (!visited[k])
                        dfs(k);
            }
        };

        vector<vector<string>> res;
        for (size_t i = 0; i < accounts.size(); i++) {
            if (visited[i])
                continue;

            email_set.clear();
            dfs(i);

            res.emplace_back(1, accounts[i][0]);
            res.back().insert(res.back().end(), email_set.begin(), email_set.end());
            sort(res.back().begin() + 1, res.back().end());
        }
        return res;
    }
};
