#include <string>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res;
        size_t i = 0, j = 0;
        for ( ; i < word1.size() && j < word2.size(); i++, j++) {
            res.push_back(word1[i]);
            res.push_back(word2[j]);
        }
        res += i == word1.size() ? word2.substr(j) : word1.substr(i);
        return res;
    }
};
