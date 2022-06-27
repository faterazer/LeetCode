#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs)
    {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        for (size_t i = 0; i < strs.size(); ++i) {
            int j = 0;
            for (; j < strs.size(); ++j) {
                if (i == j)
                    continue;
                if (isSubseq(strs[j], strs[i]))
                    break;
            }
            if (j == strs.size())
                return strs[i].size();
        }
        return -1;
    }

private:
    bool isSubseq(const string& a, const string& b)
    {
        // Return true if b is a subsequence of a.
        int ai = 0, bi = 0;
        while (ai < a.size() && bi < b.size()) {
            if (a[ai] == b[bi])
                ++bi;
            ++ai;
        }
        return bi == b.size();
    }
};
