#include <regex>
#include <string>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse_MK1(string word)
    {
        int uc = 0;
        for (size_t i = 0; i < word.size(); i++) {
            if (isupper(word[i]) && uc++ < i)
                return false;
        }
        return uc == word.size() || uc <= 1;
    }

    bool detectCapitalUse_MK2(string word)
    {
        regex reg("[A-Z]*|.[a-z]*");
        return regex_match(word, reg);
    }
};
