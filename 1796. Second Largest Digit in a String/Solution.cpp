#include <string>
using namespace std;

class Solution
{
public:
    int secondHighest(string s)
    {
        int digit = 0, cnt = 0;
        for (const char &c : s)
            if (isdigit(c))
                digit |= 1 << (c - '0');

        for (int i = 9; i >= 0; i--) 
            if (digit & (1 << i) && ++cnt == 2)
                return i;
        return -1;
    }
};
