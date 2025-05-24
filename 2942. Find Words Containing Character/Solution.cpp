#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x)
    {
        vector<int> ans;
        for (size_t i = 0; i < words.size(); ++i)
            if (words[i].find(x) != string::npos)
                ans.emplace_back(i);
        return ans;
    }
};
