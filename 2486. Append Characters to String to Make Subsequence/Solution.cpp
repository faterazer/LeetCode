#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t)
    {
        size_t j = 0;
        for (size_t i = 0; i < s.size(); i++)
            if (s[i] == t[j])
                j++;
        return t.size() - j;
    }
};
