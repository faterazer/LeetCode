#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        unordered_map<string, int> word_cnt;
        for (const string& w : words)
            ++word_cnt[w];
        int word_len = words[0].size(), all_words_len = words.size() * word_len, n = s.size();
        for (int i = 0; i < word_len; ++i) {
            if (i + all_words_len > n)
                break;
            int left = i, right = i;
            unordered_map<string, int> tmp_cnt;
            for (; right < n && right < left + all_words_len - word_len; right += word_len)
                ++tmp_cnt[s.substr(right, word_len)];
            for (; right < n; left += word_len, right += word_len) {
                ++tmp_cnt[s.substr(right, word_len)];
                if (valid(word_cnt, tmp_cnt))
                    res.emplace_back(left);
                --tmp_cnt[s.substr(left, word_len)];
            }
        }
        return res;
    }

private:
    bool valid(const unordered_map<string, int>& word_cnt, const unordered_map<string, int>& tmp_cnt)
    {
        for (const auto& it : word_cnt)
            if (!tmp_cnt.count(it.first) || it.second != tmp_cnt.at(it.first))
                return false;
        return true;
    }
};
