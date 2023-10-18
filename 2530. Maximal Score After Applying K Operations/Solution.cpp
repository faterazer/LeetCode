#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        long long res = 0;
        priority_queue<int> pq(less<int>(), std::move(nums));
        while (k--) {
            int x = pq.top();
            pq.pop();
            res += x;
            pq.emplace((x + 2) / 3);
        }
        return res;
    }
};
