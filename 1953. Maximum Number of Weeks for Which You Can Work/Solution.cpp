#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones)
    {
        long long max_val = *max_element(milestones.begin(), milestones.end());
        long long total = accumulate(milestones.begin(), milestones.end(), 0LL);
        return 2 * max_val > total ? 2 * (total - max_val) + 1 : total;
    }
};
