#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies);
};

vector<bool> Solution::kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int max_candies = *max_element(candies.begin(), candies.end());
    vector<bool> ret;
    for (size_t i = 0; i < candies.size(); i++)
        ret.emplace_back(candies[i] + extraCandies >= max_candies);
    return ret;
}
