#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        if (!next_permutation(s.begin(), s.end()))
            return -1;
        int res = 0;
        for (const char& c : s) {
            int d = c - '0';
            if (res > (INT_MAX - d) / 10)
                return -1;
            res = res * 10 + d;
        }
        return res;
    }
};
