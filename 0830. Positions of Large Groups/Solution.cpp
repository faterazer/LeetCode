#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> res;
        s.push_back('#');
        int n = s.size();
        for (int start = 0, i = 1; i != n; i++) {
            if (s[i] != s[i - 1]) {
                if (i - start >= 3)
                    res.push_back({start, i - 1});
                start = i;
            }
        }
        return res;
    }
};                            
