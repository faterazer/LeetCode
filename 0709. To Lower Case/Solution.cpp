#include <string>
using namespace std;

class Solution
{
public:
    string toLowerCase(string str)
    {
        for (char &ch : str)
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
        return str;
    }
};
