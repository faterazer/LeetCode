#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int n = sequence.size(), m = word.size(), res = 0;
        vector<int> next(n);
        next[0] = 0;
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && word[i % m] != word[j % m])
                j = next[j - 1];
            if (word[i % m] == word[j % m])
                j++;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && sequence[i] != word[j % m])
                j = next[j - 1];
            if (sequence[i] == word[j % m])
                j++;
            res = max(res, j / m);
        }
        return res;
    }
};
