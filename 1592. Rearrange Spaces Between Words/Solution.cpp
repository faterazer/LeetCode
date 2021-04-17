#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string reorderSpaces(string text)
    {
        vector<string> wordlist;
        string word, res;
        istringstream in(text);
        int spaces = text.size(), gap = 0, tail;
        while (in >> word) {
            wordlist.emplace_back(word);
            spaces -= word.size();
        }
        if (wordlist.size() > 1)
            gap = spaces / (wordlist.size() - 1);
        tail = spaces - gap * (wordlist.size() - 1);
        for (const string &w : wordlist) {
            if (!res.empty())
                res += string(gap, ' ');
            res += w;
        }
        return res + string(tail, ' ');
    }
};
