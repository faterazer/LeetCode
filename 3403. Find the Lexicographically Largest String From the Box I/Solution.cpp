#include <string>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
            return word;
        int n = word.size(), i = 0, j = 1;
        while (j < n) {
            int nc = 0;
            while (j + nc < n && word[i + nc] == word[j + nc])
                ++nc;
            if (j + nc < n && word[i + nc] < word[j + nc]) {
                int tmp = i;
                i = j;
                j = max(j + 1, tmp + nc + 1);
            } else
                j += nc + 1;
        }
        return word.substr(i, n - max(numFriends - 1, i));
    }
};
