#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2)
    {
        int n = wordsDict.size(), res = n, idx1 = -n, idx2 = -n;
        for (int i = 0; i < n; i++) {
            if (wordsDict[i] == word1) {
                idx1 = i;
                res = min(res, idx1 - idx2);
            } else if (wordsDict[i] == word2) {
                idx2 = i;
                res = min(res, idx2 - idx1);
            }
        }
        return res;
    }
};
