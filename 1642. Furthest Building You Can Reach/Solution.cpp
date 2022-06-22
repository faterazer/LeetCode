#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (size_t i = 1; i < heights.size(); ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0)
                pq.emplace(diff);
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i - 1;
        }
        return heights.size() - 1;
    }
};
