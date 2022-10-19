#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string, int> cnt;
        for (const string& word : words)
            ++cnt[word];
        auto cmp = [](const pair<string, int>& left, const pair<string, int>& right) {
            return left.second == right.second ? left.first < right.first : left.second > right.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> Q(cmp);
        for (const auto& it : cnt) {
            Q.emplace(it);
            if (Q.size() > k)
                Q.pop();
        }
        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = Q.top().first;
            Q.pop();
        }
        return res;
    }
};
