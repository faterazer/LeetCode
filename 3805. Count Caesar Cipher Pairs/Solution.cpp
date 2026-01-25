#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words)
    {
        unordered_map<string, int> word_counts;
        for (const string& word : words)
            ++word_counts[word];

        long long result = 0;
        unordered_map<string, long long> cnt;
        for (auto& [word, freq] : word_counts) {
            string t = move(word);
            int base = t[0] - 'a';
            for (char& ch : t)
                ch = (ch - base + 26) % 26 + 'a';
            result += cnt[t] * freq + 1LL * freq * (freq - 1) / 2;
            cnt[t] += freq;
        }
        return result;
    }
};
