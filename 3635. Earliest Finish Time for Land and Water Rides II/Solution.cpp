#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration)
    {
        auto solve = [](const vector<int>& t1, const vector<int>& d1, const vector<int>& t2, const vector<int>& d2) -> int {
            int mn = numeric_limits<int>::max();
            for (size_t i = 0; i < t1.size(); ++i)
                mn = min(t1[i] + d1[i], mn);
            int result = numeric_limits<int>::max();
            for (size_t i = 0; i < t2.size(); ++i)
                result = min(result, max(mn, t2[i]) + d2[i]);
            return result;
        };

        int land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
