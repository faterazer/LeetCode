#include <string>
using namespace std;

class Solution {
public:
    int minimumMoves(string s)
    {
        int n = s.size(), i = 0, res = 0;
        while (i < n) {
            if (s[i] == 'O')
                ++i;
            else {
                i += 3;
                ++res;
            }
        }
        return res;
    }
};
