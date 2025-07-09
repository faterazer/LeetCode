#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
    {
        int n = startTime.size();

        function<int(int)> get = [&](int i) -> int {
            if (i == 0)
                return startTime[0];
            else if (i == n)
                return eventTime - endTime[n - 1];
            else
                return startTime[i] - endTime[i - 1];
        };

        int s = 0, ans = 0;
        for (int i = 0; i <= n; ++i) {
            s += get(i);
            if (i < k)
                continue;
            ans = max(ans, s);
            s -= get(i - k);
        }
        return ans;
    }
};
