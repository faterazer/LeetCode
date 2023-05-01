#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        function<int(int)> dfs = [&](int i) -> int {
            if (manager[i] != -1) {
                informTime[i] += dfs(manager[i]);
                manager[i] = -1;
            }
            return informTime[i];
        };

        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, dfs(i));
        return res;
    }
};
