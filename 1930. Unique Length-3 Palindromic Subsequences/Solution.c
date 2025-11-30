#include <stdbit.h>

int countPalindromicSubsequence(char* s)
{
    int suf_cnt[26] = { 0 };
    unsigned suf_mask = 0;
    for (int i = 1; s[i]; ++i) {
        int k = s[i] - 'a';
        ++suf_cnt[k];
        suf_mask |= 1 << k;
    }

    unsigned pre_mask = 0;
    unsigned letter_masks[26] = { 0 };
    for (int i = 1; s[i]; ++i) {
        int k = s[i] - 'a';
        --suf_cnt[k];
        if (suf_cnt[k] == 0)
            suf_mask ^= 1 << k;
        pre_mask |= 1 << (s[i - 1] - 'a');
        letter_masks[k] |= pre_mask & suf_mask;
    }

    int result = 0;
    for (int i = 0; i < 26; ++i)
        result += stdc_count_ones(letter_masks[i]);
    return result;
}
