#include <string>
using namespace std;

class Solution {
public:
    int maxOperations(string s)
    {
        int result = 0, cnt1 = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++cnt1;
            else if (i > 0 && s[i - 1] == '1')
                result += cnt1;
        }
        return result;
    }
};
