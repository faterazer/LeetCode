#include <vector>
using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold)
    {
        vector<int> ans;
        for (size_t i = 1; i < height.size(); ++i)
            if (height[i - 1] > threshold)
                ans.emplace_back(i);
        return ans;
    }
};
