#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s)
    {
        long long cnt = 0, res = 0;
        for (char c : s) {
            if (c == '1')
                cnt++;
            else
                res += cnt;
        }
        return res;
    }
};
