#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s);
};

int Solution::findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gi = 0;
    for (size_t sj = 0; sj < s.size() && gi < g.size(); sj++)
        if (s[sj] >= g[gi])
            gi++;
    return gi;
}
