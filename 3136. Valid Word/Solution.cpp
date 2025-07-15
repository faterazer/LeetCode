#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
            return false;

        unsigned flag = 0;
        for (char c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    flag |= 1; // vowel
                else
                    flag |= 2; // consonant
            } else if (!isdigit(c))
                return false;
        }
        return flag == 3;
    }
};
