#include <vector>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums)
    {
        int cnt[101] = { 0 };
        for (int x : nums)
            if (++cnt[x] > 2)
                return false;
        return true;
    }
};
