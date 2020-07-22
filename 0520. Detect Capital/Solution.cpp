#include <string>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int uc = 0;
        for (size_t i = 0; i < word.size(); i++) {
            if (isupper(word[i]) && uc++ < i)
                return false;
        }
        return uc == word.size() || uc <= 1;
    }
};
