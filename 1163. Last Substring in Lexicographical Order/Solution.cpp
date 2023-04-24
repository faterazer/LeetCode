#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
    string lastSubstring(string s)
    {
        int n = s.size(), i = 0;
        for (int j = 1, k = 0; j + k < n;) {
            if (s[i + k] == s[j + k])
                k++;
            else if (s[i + k] < s[j + k]) {
                i += k + 1;
                k = 0;
                if (i >= j)
                    j = i + 1;
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
