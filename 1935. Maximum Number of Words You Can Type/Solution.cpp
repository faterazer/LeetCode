#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int addition = 1, res = 0;
        for (const char &c : text) {
            if (c == ' ') {
                res += addition;
                addition = 1;
            } else if (broken.count(c))
                addition = 0;
        }
        return res + addition;
    }
};
