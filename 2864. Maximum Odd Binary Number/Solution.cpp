#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        int odds = -1, evens = 0;
        for (char c : s) {
            if (c == '0')
                ++evens;
            else
                ++odds;
        }
        return string(odds, '1') + string(evens, '0') + '1';
    }
};
