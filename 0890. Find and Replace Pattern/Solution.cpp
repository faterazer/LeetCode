#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string> res;
        for (const string& word : words) {
            bool is_match = true;
            for (size_t i = 0; i < word.size(); ++i) {
                if (word.find(word[i]) != pattern.find(pattern[i])) {
                    is_match = false;
                    break;
                }
            }
            if (is_match)
                res.emplace_back(word);
        }
        return res;
    }
};
