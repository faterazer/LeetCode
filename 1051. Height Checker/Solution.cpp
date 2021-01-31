#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int res = 0;
        vector<int> buff(heights);
        sort(buff.begin(), buff.end());
        for (size_t i = 0; i < heights.size(); i++)
            if (heights[i] != buff[i])
                res++;
        return res;
    }
};
