#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones)
    {
        sort(stones.begin(), stones.end());
        int i = 0, n = stones.size();
        int max_moves = max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - n + 2;
        int min_moves = n;
        for (int j = 0; j < n; j++) {
            while (stones[j] - stones[i] + 1 > n)
                i++;
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1)
                min_moves = min(min_moves, 2);
            else
                min_moves = min(min_moves, n - (j - i + 1));
        }
        return { min_moves, max_moves };
    }
};
