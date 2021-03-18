#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream in(sentence);
        string word;
        for (int i = 1; in >> word; i++)
            if (word.find(searchWord) == 0)
                return i;
        return -1;
    }
};
