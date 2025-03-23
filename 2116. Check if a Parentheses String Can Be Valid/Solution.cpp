#include <string>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.size();
        if (n % 2 == 1)
            return false;

        int unlocked_cnt = 0, locked_left = 0, used_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                if (locked_left > 0) {
                    --locked_left;
                    ++used_cnt;
                } else
                    ++unlocked_cnt;
            } 
            else if (s[i] == '(')
                ++locked_left;
            else {
                if (locked_left > 0)
                    --locked_left;
                else if (used_cnt > 0) {
                    --used_cnt;
                    ++unlocked_cnt;
                } else if (unlocked_cnt > 0)
                    --unlocked_cnt;
                else
                    return false;
            }
        }
        return locked_left == 0 && unlocked_cnt % 2 == 0;
    }
};
