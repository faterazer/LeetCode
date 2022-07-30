#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        unordered_map<char, int> cnt;
        for (const string& word : words2) {
            unordered_map<char, int> tmp = wordCount(word);
            for (const auto& it : tmp)
                cnt[it.first] = max(cnt[it.first], it.second);
        }

        vector<string> res;
        for (const string& s : words1) {
            unordered_map<char, int> tmp = wordCount(s);
            bool flag = true;
            for (const auto& it : cnt) {
                if (!tmp.count(it.first) || tmp[it.first] < it.second) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.emplace_back(s);
        }
        return res;
    }

private:
    unordered_map<char, int> wordCount(const string& s)
    {
        unordered_map<char, int> res;
        for (const char& c : s)
            ++res[c];
        return res;
    }
};
