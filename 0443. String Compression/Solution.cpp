#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size(), i = 0, idx = 0;
        while (i < n) {
            int ch = chars[i++], cnt = 1;
            while (i < n && chars[i] == ch) {
                ++i;
                ++cnt;
            }
            chars[idx++] = ch;

            if (cnt > 1) {
                int start = idx;
                while (cnt) {
                    chars[idx++] = cnt % 10 + '0';
                    cnt /= 10;
                }
                reverse(chars.begin() + start, chars.begin() + idx);
            }
        }
        return idx;
    }
};
