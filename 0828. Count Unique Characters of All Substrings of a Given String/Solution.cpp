#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueLetterString(const string& s)
    {
        int indices[26][2];
        memset(indices, -1, sizeof(int) * 52);

        int n = s.size(), res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'A';
            res += (indices[idx][1] - indices[idx][0]) * (i - indices[idx][1]);
            indices[idx][0] = indices[idx][1];
            indices[idx][1] = i;
        }
        for (int i = 0; i < 26; ++i)
            res += (indices[i][1] - indices[i][0]) * (n - indices[i][1]);
        return res;
    }
};
