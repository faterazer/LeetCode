#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_map<string, int> counter;
        unordered_set<string> ban(banned.begin(), banned.end());
        for (char &ch : paragraph)
            ch = isalpha(ch) ? tolower(ch) : ' ';
        istringstream iss(paragraph);
        pair<string, int> res("", 0);
        string word;
        while (iss >> word)
            if (!ban.count(word) && ++counter[word] > res.second)
                res = make_pair(word, counter[word]);
        return res.first;
    }
};
