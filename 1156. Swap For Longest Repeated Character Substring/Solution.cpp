#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxRepOpt1(string text)
    {
        unordered_map<char, int> cnt{{text[0], 1}};
        vector<pair<char, int>> groups{{text[0], 1}};
        for (size_t i = 1; i < text.size(); i++)
        {
            cnt[text[i]]++;
            if (text[i] == text[i - 1])
                groups.back().second++;
            else
                groups.emplace_back(text[i], 1);
        }

        int res = 0;
        for (size_t i = 0; i < groups.size(); i++)
        {
            pair<char, int> &p = groups[i];
            res = max(res, min(p.second + 1, cnt[p.first]));
            if (p.second == 1 && i > 0 && i + 1 < groups.size() && groups[i - 1].first == groups[i + 1].first)
                res = max(res, min(groups[i - 1].second + groups[i + 1].second + 1, cnt[groups[i - 1].first]));
        }
        return res;
    }
};
