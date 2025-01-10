#include <string>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2)
    {
        if (word1.size() < word2.size())
            return 0;

        int diff[26] = { 0 };
        for (const char& c : word2)
            ++diff[c - 'a'];

        int less = 0;
        for (const int& d : diff)
            less += d > 0;

        long long ans = 0;
        int n = word1.size(), i = 0;
        for (int j = 0; j < n; ++j) {
            --diff[word1[j] - 'a'];
            less -= diff[word1[j] - 'a'] == 0;
            if (less > 0)
                continue;

            while (less == 0) {
                ans += n - j;
                if (diff[word1[i] - 'a'] == 0)
                    ++less;
                ++diff[word1[i++] - 'a'];
            }
        }
        return ans;
    }
};
