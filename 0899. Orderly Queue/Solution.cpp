#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        } else {
            int offset = 0, i = 0, j = 1, n = s.size();
            while (offset < n && i < n && j < n) {
                if (s[(i + offset) % n] == s[(j + offset) % n])
                    ++offset;
                else {
                    s[(i + offset) % n] > s[(j + offset) % n] ? i = i + offset + 1 : j = j + offset + 1;
                    if (i == j)
                        ++i;
                    offset = 0;
                }
            }
            i = min(i, j);
            return s.substr(i) + s.substr(0, i);
        }
    }
};
