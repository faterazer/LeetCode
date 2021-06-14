#include <string>
using namespace std;

class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        auto word2num = [](const string &s) -> int {
            int res = 0;
            for (const char &c : s)
                res = res * 10 + c - 'a';
            return res;
        };
        return word2num(firstWord) + word2num(secondWord) == word2num(targetWord);
    }
};
