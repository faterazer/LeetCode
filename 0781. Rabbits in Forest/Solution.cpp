#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers)
    {
        unordered_map<int, int> cnt;
        for (int x : answers)
            ++cnt[x];

        int ans = 0;
        for (auto& [x, c] : cnt)
        {
            int group = x + 1;
            ans += (c + group - 1) / group * group;
        }
        return ans;
    }
};
