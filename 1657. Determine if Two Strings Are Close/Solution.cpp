#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 != n2)
            return false;

        unsigned mask1 = 0, mask2 = 0;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < n1; ++i) {
            int idx1 = word1[i] - 'a', idx2 = word2[i] - 'a';
            mask1 |= 1 << idx1;
            mask2 |= 1 << idx2;
            cnt1[idx1]++;
            cnt2[idx2]++;
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        return mask1 == mask2 && cnt1 == cnt2;
    }
};
