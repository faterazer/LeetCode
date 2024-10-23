#include <vector>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours)
    {
        long long ans = 0, cnt[24] = { 0 };
        for (int h : hours) {
            ans += cnt[(24 - h % 24) % 24];
            ++cnt[h % 24];
        }
        return ans;
    }
};
