#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration)
    {
        auto&& helper = [](const vector<int>& start_time1, const vector<int>& duration1, const vector<int>& start_time2, const vector<int>& duration2) -> int {
            int min_finish = numeric_limits<int>::max();
            for (size_t i = 0; i < start_time1.size(); ++i)
                min_finish = min(min_finish, start_time1[i] + duration1[i]);

            int result = numeric_limits<int>::max();
            for (size_t i = 0; i < start_time2.size(); ++i)
                result = min(result, max(min_finish, start_time2[i]) + duration2[i]);
            return result;
        };

        return min(helper(landStartTime, landDuration, waterStartTime, waterDuration), helper(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};
