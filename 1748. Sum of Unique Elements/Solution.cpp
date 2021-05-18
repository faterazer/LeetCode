#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int res = 0;
        unordered_map<int, int> cnt;
        for (const int &x : nums)
            cnt[x]++;
        for (auto it = cnt.begin(); it != cnt.end(); it++)
            if (it->second == 1)
                res += it->first;
        return res;
    }
};
