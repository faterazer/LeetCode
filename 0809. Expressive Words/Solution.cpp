#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words)
    {
        int res = 0;
        for (const string& word : words)
            res += isExpressive(s, word);
        return res;
    }

private:
    bool isExpressive(const string& s, const string& t)
    {
        int si = 0, ti = 0, sn = s.size(), tn = t.size();
        while (si < sn && ti < tn) {
            if (s[si] != t[ti])
                return false;
            int sj = si + 1;
            while (sj < sn && s[sj] == s[si])
                ++sj;

            int tj = ti + 1;
            while (tj < tn && t[tj] == t[ti])
                ++tj;

            int s_cnt = sj - si, t_cnt = tj - ti;
            if ((t_cnt < s_cnt && s_cnt < 3) || s_cnt < t_cnt)
                return false;
            si = sj;
            ti = tj;
        }
        return si == sn && ti == tn;
    }
};
