#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k)
    {
        unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u' };
        unordered_map<char, int> vowel_cnt;
        size_t i = 0, v = 0;
        int consonants = 0;
        long long ans = 0;
        for (size_t j = 0; j < word.size(); ++j) {
            char c = word[j];
            vowels.contains(c) ? ++vowel_cnt[c] : ++consonants;
            while (consonants > k) {
                c = word[v++];
                i = v;
                vowels.contains(c) ? --vowel_cnt[c] : --consonants;
                if (!vowel_cnt[c])
                    vowel_cnt.erase(c);
            }
            if (vowel_cnt.size() == 5 && consonants == k) {
                for (; vowels.contains(word[v]) && vowel_cnt[word[v]] > 1; ++v)
                    --vowel_cnt[word[v]];
                ans += v - i + 1;
            }
        }
        return ans;
    }
};
