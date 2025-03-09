#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        ranges::sort(items, {}, [](const vector<int>& item) {
            return item[0];
        });
        int last = 0;
        for (size_t i = 1; i < items.size(); ++i)
            if (items[i][1] > items[last][1])
                items[++last] = items[i];
        items.resize(last + 1);

        vector<int> ans;
        ans.reserve(queries.size());
        for (int query : queries) {
            auto it = upper_bound(items.begin(), items.end(), query, [](int val, const vector<int>& item) {
                return val < item[0];
            });
            ans.emplace_back(it == items.begin() ? 0 : (*prev(it))[1]);
        }
        return ans;
    }
};
