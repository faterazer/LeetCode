#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        vector<int> visited(bank.size(), 0);
        int cnt = 0;
        queue<string> Q;
        Q.emplace(start);
        while (!Q.empty()) {
            ++cnt;
            int n = Q.size();
            for (int i = 0; i < n; ++i) {
                string s = Q.front();
                Q.pop();
                for (int j = 0; j < bank.size(); ++j) {
                    if (!visited[j] && isMutation(s, bank[j])) {
                        if (bank[j] == end)
                            return cnt;
                        else {
                            visited[j] = 1;
                            Q.emplace(bank[j]);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    bool isMutation(const string& old_s, const string& new_s)
    {
        int cnt = 0;
        for (int i = 0; i < old_s.size(); ++i) {
            cnt += old_s[i] != new_s[i];
            if (cnt > 1)
                return false;
        }
        return cnt == 1;
    }
};
