#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (const vector<int>& interval : intervals) {
            while (!pq.empty() && pq.top() <= interval[0])
                pq.pop();
            pq.emplace(interval[1]);
            res = max(res, static_cast<int>(pq.size()));
        }
        return res;
    }
};
