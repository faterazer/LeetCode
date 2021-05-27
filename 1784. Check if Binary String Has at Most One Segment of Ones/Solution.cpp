#include <string>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment_MK1(string s)
    {
        int cnt = 0;
        for (size_t i = 1; i < s.size(); i++)
            if (s[i] ^ s[i - 1] && ++cnt > 1)
                return false;
        return true;
    }

    bool checkOnesSegment_MK2(string s)
    {
        return s.find("01") == string::npos;
    }
};
