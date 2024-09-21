#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges)
    {
        vector<unsigned> scores(edges.size(), 0);
        for (size_t i = 0; i < edges.size(); ++i)
            scores[edges[i]] += i;
        return ranges::max_element(scores) - scores.begin();
    }
};
