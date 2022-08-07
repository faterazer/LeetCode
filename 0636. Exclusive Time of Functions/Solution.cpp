#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        vector<int> res(n, 0);
        stack<pair<int, int>> stk;
        for (const string& log : logs) {
            char type[8];
            int id, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &id, type, &timestamp);
            if (type[0] == 's') {
                if (!stk.empty())
                    res[stk.top().first] += timestamp - stk.top().second;
                stk.emplace(id, timestamp);
            } else {
                pair<int, int>& p = stk.top();
                stk.pop();
                res[p.first] += timestamp - p.second + 1;
                if (!stk.empty())
                    stk.top().second = timestamp + 1;
            }
        }
        return res;
    }
};
