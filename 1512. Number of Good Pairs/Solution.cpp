#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int res = 0;
        unordered_map<int, int> counter;
        for (const int &x : nums)
            res += counter[x]++;
        return res;
    }
};
