#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones);
};

int Solution::lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> Q(stones.begin(), stones.end());
    while (Q.size() > 1) {
        int x = Q.top(); Q.pop();
        int y = Q.top(); Q.pop();
        if (x > y)
            Q.emplace(x - y);
    }
    return Q.empty() ? 0 : Q.top();
}
