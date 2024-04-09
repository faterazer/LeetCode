#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k)
    {
        int res = 0;
        for (size_t i = 0; i < tickets.size(); i++)
            res += i <= k ? min(tickets[i], tickets[k]) : min(tickets[i], tickets[k] - 1);
        return res;
    }
};
