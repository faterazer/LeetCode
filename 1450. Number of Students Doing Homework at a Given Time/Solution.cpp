#include <vector>
using namespace std;

class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int len = startTime.size();
        int res = 0;
        for (int i = 0; i < len; i++)
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
                res++;
        return res;
    }
};
