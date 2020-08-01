#include <algorithm>
#include <regex>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkRecord_MK1(string s)
    {
        int absent = 0, contin_late = 0;
        for (const char &ch : s) {
            if (ch == 'L')
                contin_late++;
            else {
                contin_late = 0;
                if (ch == 'A')
                    absent++;
            }
            if (absent > 1 || contin_late > 2)
                return false;
        }
        return true;
    }

    bool checkRecord_MK2(string s)
    {
        return count(s.begin(), s.end(), 'A') <= 1 && s.find("LLL") == s.npos;
    }

    bool checkRecord_MK3(string s)
    {
        regex reg("A.*A|LLL");
        return !regex_search(s, reg);
    }
};
