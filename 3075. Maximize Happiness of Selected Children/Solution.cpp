#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        ranges::sort(happiness, greater{});
        long long result = 0;
        for (int i = 0; i < k && happiness[i] > i; ++i)
            result += max(happiness[i] - i, 0);
        return result;
    }
};
