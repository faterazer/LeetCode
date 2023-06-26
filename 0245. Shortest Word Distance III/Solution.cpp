#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2)
    {
        int res = INT_MAX, n = wordsDict.size(), idx1 = -1, idx2 = -1;
        bool is_same = word1 == word2;
        for (int i = 0; i < n; i++) {
            if (wordsDict[i] == word1) {
                idx1 = i;
                if (is_same)
                    swap(idx1, idx2);
                if (idx1 != -1 && idx2 != -1)
                    res = min(res, abs(idx1 - idx2));
            } else if (wordsDict[i] == word2) {
                idx2 = i;
                if (idx1 != -1 && idx2 != -1)
                    res = min(res, idx2 - idx1);
            }
        }
        return res;
    }
};
