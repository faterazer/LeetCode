#include <bit>
#include <numeric>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        int suf_cnt[26] {};
        unsigned suf_mask = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            int k = s[i] - 'a';
            ++suf_cnt[k];
            suf_mask |= 1 << k;
        }

        unsigned pre_mask = 0, letter_masks[26] {};
        for (size_t i = 1; i < s.size() - 1; ++i) {
            int mid = s[i] - 'a';
            --suf_cnt[mid];
            if (suf_cnt[mid] == 0)
                suf_mask ^= 1 << mid;
            pre_mask |= 1 << (s[i - 1] - 'a');
            letter_masks[mid] |= pre_mask & suf_mask;
        }

        int result = 0;
        for (unsigned m : letter_masks)
            result += popcount(m);
        return result;
    }
};
