#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> dict;
        for (size_t i = 0; i < order.size(); i++)
            dict[order[i]] = i + 1;
        for (size_t i = 1; i < words.size(); i++)
            if (wordCmp(words[i - 1], words[i], dict) > 0)
                return false;
        return true;
    }

private:
    int wordCmp(const string &s1, const string &s2, const unordered_map<char, int> &dict)
    {
        size_t i = 0, j = 0;
        for (; i < s1.size() && j < s2.size() && s1[i] == s2[j]; i++, j++)
            ;
        int a = i == s1.size() ? 0 : dict.at(s1[i]);
        int b = j == s2.size() ? 0 : dict.at(s2[j]);
        return a - b;
    }
};
