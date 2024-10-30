#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(string s)
    {
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i - 1] % 2 == s[i] % 2 && s[i] < s[i - 1]) {
                swap(s[i - 1], s[i]);
                break;
            }
        }
        return s;
    }
};
