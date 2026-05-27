#include <array>
#include <bit>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word)
    {
        unsigned lower = 0, upper = 0, invalid = 0;
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                int bit = 1 << (c - 'a');
                lower |= bit;
                if (upper & bit)
                    invalid |= bit;
            } else {
                int bit = 1 << (c - 'A');
                upper |= bit;
            }
        }
        return popcount(lower & upper & ~invalid);
    }
};
