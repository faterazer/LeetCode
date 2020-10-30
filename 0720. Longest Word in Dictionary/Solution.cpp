#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_set<string> dict;
        string ret;
        for (const string &word : words) {
            if (word.size() == 1 || dict.count(word.substr(0, word.size() - 1))) {
                dict.insert(word);
                if (word.size() > ret.size())
                    ret = word;
            }
        }
        return ret;
    }
};
