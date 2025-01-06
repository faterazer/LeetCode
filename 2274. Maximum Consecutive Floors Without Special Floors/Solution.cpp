#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special)
    {
        ranges::sort(special);
        int last_floor = bottom, ans = 0;
        for (int floor : special) {
            ans = max(ans, floor - last_floor);
            last_floor = floor + 1;
        }
        return max(ans, top - last_floor + 1);
    }
};
