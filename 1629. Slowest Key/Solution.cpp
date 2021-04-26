#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        char res = keysPressed.front();
        int max_dur = releaseTimes.front(), n = releaseTimes.size(), dur;
        for (int i = 1; i < n; i++) {
            dur = releaseTimes[i] - releaseTimes[i - 1];
            if (dur > max_dur) {
                max_dur = dur;
                res = keysPressed[i];
            }
            else if (dur == max_dur)
                res = max(res, keysPressed[i]);
        }
        return res;
    }
};
