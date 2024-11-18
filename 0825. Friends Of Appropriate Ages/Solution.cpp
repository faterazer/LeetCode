#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages)
    {
        int cnt[121] = { 0 };
        for (int age : ages)
            ++cnt[age];

        int ans = 0, age_y = 0, cnt_window = 0;
        for (int age_x = 0; age_x < 121; ++age_x) {
            cnt_window += cnt[age_x];
            if (age_y * 2 <= age_x + 14) {
                cnt_window -= cnt[age_y];
                ++age_y;
            }
            if (cnt_window > 0)
                ans += cnt_window * cnt[age_x] - cnt[age_x];
        }
        return ans;
    }
};
