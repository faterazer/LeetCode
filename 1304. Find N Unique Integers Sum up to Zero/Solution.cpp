#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res(n);
        ranges::iota(res, 0);
        res[0] = -n * (n - 1) / 2;
        return res;
    }
};
