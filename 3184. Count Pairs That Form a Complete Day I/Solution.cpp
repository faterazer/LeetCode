#include <vector>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours)
    {
        int ans = 0;
        int cnt[24] = { 0 };
        for (int h : hours) {
            ans += cnt[(24 - h % 24) % 24];
            ++cnt[h % 24];
        }
        return ans;
    }
};
