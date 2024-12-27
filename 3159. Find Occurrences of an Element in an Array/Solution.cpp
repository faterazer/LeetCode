#include <vector>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x)
    {
        vector<int> indices;
        for (size_t i = 0; i < nums.size(); ++i)
            if (nums[i] == x)
                indices.emplace_back(i);

        vector<int> res;
        res.reserve(queries.size());
        for (int query : queries) {
            if (query > indices.size())
                res.emplace_back(-1);
            else
                res.emplace_back(indices[query - 1]);
        }
        return res;
    }
};
