#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        vector<vector<int>> candidates;
        for (const vector<int>& restaurant : restaurants)
            if (restaurant[2] >= veganFriendly && restaurant[3] <= maxPrice && restaurant[4] <= maxDistance)
                candidates.emplace_back(restaurant);
        sort(candidates.begin(), candidates.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] != b[1] ? a[1] > b[1] : a[0] > b[0];
        });
        vector<int> res(candidates.size());
        for (size_t i = 0; i < candidates.size(); i++)
            res[i] = candidates[i][0];
        return res;
    }
};
