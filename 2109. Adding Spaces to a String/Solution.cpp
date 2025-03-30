#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int m = s.size(), n = spaces.size();
        string ans;
        ans.reserve(m + n);
        for (int i = 0, j = 0; i < m; ++i) {
            if (j < n && i == spaces[j]) {
                ans.push_back(' ');
                ++j;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
