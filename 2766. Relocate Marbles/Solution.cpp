#include <ranges>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        for (size_t i = 0; i < moveFrom.size(); i++) {
            st.erase(moveFrom[i]);
            st.emplace(moveTo[i]);
        }

        vector<int> res(st.begin(), st.end());
        ranges::sort(res);
        return res;
    }
};
