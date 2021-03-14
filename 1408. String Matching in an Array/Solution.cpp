#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        vector<string> res;
        for (size_t i = 1; i < words.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (words[j].find(words[i]) != string::npos) {
                    res.emplace_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
