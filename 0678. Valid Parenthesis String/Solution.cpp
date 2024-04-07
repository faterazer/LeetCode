#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s)
    {
        int min_cnt = 0, max_cnt = 0;
        for (char c : s) {
            if (c == '(') {
                ++min_cnt;
                ++max_cnt;
            } else if (c == ')') {
                min_cnt = max(min_cnt - 1, 0);
                if (--max_cnt < 0)
                    return false;
            } else {
                min_cnt = max(min_cnt - 1, 0);
                ++max_cnt;
            }
        }
        return min_cnt == 0;
    }
};
