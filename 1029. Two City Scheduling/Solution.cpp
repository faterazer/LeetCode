#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs);
};

int Solution::twoCitySchedCost(vector<vector<int>> &costs)
{
    int n = costs.size() >> 1;
    nth_element(costs.begin(), costs.begin() + n, costs.end(), [](const vector<int> &left, const vector<int> &right) -> bool {
        return (left[1] - left[0]) > (right[1] - right[0]);
    });
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += costs[i][0] + costs[i + n][1];
    return sum;
}
