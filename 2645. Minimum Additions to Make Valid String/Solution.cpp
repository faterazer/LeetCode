#include <string>
using namespace std;

class Solution {
public:
    int addMinimum(string word)
    {
        int res = word[0] - word.back() + 2;
        for (size_t i = 1; i < word.size(); i++)
            res += (word[i] - word[i - 1] + 2) % 3;
        return res;
    }
};
