#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        size_t i = 0, j = 0, k = 0, l = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][k] != word2[j][l])
                return false;
            k++;
            l++;
            if (k == word1[i].size()) {
                k = 0;
                i++;
            }
            if (l == word2[j].size()) {
                l = 0;
                j++;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};
