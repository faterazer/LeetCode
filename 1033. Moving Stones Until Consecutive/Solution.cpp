#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> stones{a, b, c};
        sort(stones.begin(), stones.end());
        if (stones[2] - stones[0] == 2)
            return {0, 0};
        return {min(stones[1] - stones[0], stones[2] - stones[1]) <= 2 ? 1 : 2, stones[2] - stones[0] - 2};
    }
};
