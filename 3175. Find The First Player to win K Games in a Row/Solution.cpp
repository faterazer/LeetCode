#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k)
    {
        int max_i = 0, cnt = 0;
        for (size_t i = 1; i < skills.size() && cnt < k; ++i) {
            if (skills[i] > skills[max_i]) {
                max_i = i;
                cnt = 0;
            }
            ++cnt;
        }
        return max_i;
    }
};
