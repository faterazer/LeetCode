#include <string>
using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k)
    {
        int i = 0, n = s.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i])
                ++j;
            if (j - i == k)
                return true;
            i = j;
        }
        return false;
    }
};
