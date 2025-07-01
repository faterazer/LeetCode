#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word)
    {
        int ans = 1;
        for (size_t i = 1; i < word.size(); ++i)
            if (word[i] == word[i - 1])
                ++ans;
        return ans;
    }
};
