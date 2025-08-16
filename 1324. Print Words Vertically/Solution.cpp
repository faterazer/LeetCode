#include <algorithm>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s)
    {
        vector<string_view> words;
        for (auto word : string_view { s } | ranges::views::split(' '))
            words.emplace_back(word);

        int max_len = ranges::max(words, {}, [](const string_view& x) { return x.size(); }).size();
        vector<string> result(max_len, string(words.size(), ' '));
        for (size_t i = 0; i < words.size(); ++i)
            for (size_t j = 0; j < words[i].size(); ++j)
                result[j][i] = words[i][j];
        for (string &r : result)
            r.erase(r.find_last_not_of(' ') + 1);
        return result;
    }
};
