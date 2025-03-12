#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k)
    {
        unordered_set<char> vowel_set { 'a', 'e', 'i', 'o', 'u' };
        unordered_map<char, int> vowel_cnt;
        int ans = 0, i = 0, v = 0, n = word.size(), consonants = 0;
        for (int j = 0; j < n; ++j) {
            char c = word[j];
            vowel_set.contains(c) ? ++vowel_cnt[c] : ++consonants;
            while (consonants > k) {
                char d = word[v++];
                i = v;
                vowel_set.contains(d) ? --vowel_cnt[d] : --consonants;
                if (!vowel_cnt[d])
                    vowel_cnt.erase(d);
            }
            if (vowel_cnt.size() == 5 && consonants == k) {
                for (; vowel_cnt.contains(word[v]) && vowel_cnt[word[v]] > 1; ++v)
                    --vowel_cnt[word[v]];
                ans += v - i + 1;
            }
        }
        return ans;
    }
};
