#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k)
    {
        unordered_map<char, int> vowel2idx {
            { 'a', 0 }, { 'e', 1 }, { 'i', 2 }, { 'o', 3 }, { 'u', 4 }
        };
        int cnt[5] = { 0 };
        int ans = 0, i = 0, n = word.size(), consonants = 0;
        for (int j = 0; j < n; ++j) {
            char c = word[j];
            vowel2idx.contains(c) ? ++cnt[vowel2idx[c]] : ++consonants;
            while (consonants > k) {
                char d = word[i++];
                vowel2idx.contains(d) ? --cnt[vowel2idx[d]] : --consonants;
            }
            if (ranges::min(cnt) > 0 && consonants == k) {
                // cout << word.substr(i, j - i + 1) << endl;
                ++ans;
                int k = i;
                // for (int x : cnt)
                //     cout << x << " ";
                // cout << endl;
                for (k; k < j; ++k)
                    if (vowel2idx.contains(word[k]) && --cnt[vowel2idx[word[k]]] > 0) {
                        // cout << word.substr(k, j - k + 1) << endl;
                        ++ans;
                    } else {
                        ++k;
                        break;
                    }
                for (--k; k >= i; --k)
                    if (vowel2idx.contains(word[k]))
                        ++cnt[vowel2idx[word[k]]];
            }
        }

        return ans;
    }
};
