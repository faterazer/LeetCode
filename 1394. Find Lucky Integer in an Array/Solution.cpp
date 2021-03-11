#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> counter;
        for (const int &x : arr)
            counter[x]++;
        int res = -1;
        for (const auto &it : counter)
            if (it.first == it.second)
                res = max(res, it.first);
        return res;
    }
};
