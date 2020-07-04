#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        int mp[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
        vector<string> ret;
        for (const string &word : words) {
            ret.emplace_back(word);
            for (size_t i = 1; i < word.size(); i++)
                if (mp[tolower(word[i]) - 'a'] != mp[tolower(word[i - 1]) - 'a']) {
                    ret.pop_back();
                    break;
                }
        }
        return ret;
    }
};
