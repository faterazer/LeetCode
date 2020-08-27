#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {
        size_t types = unordered_set<int>(candies.begin(), candies.end()).size();
        return min(types, candies.size() / 2);
    }
};
