#include <string>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers_MK1(string answerKey, int k)
    {
        return max(maxConsecutiveAnswers(answerKey, k, 'T'), maxConsecutiveAnswers(answerKey, k, 'F'));
    }

    int maxConsecutiveAnswers_MK2(string answerKey, int k)
    {
        int t_cnt = 0, f_cnt = 0, len = 0;
        for (int i = 0; i < answerKey.size(); ++i) {
            if (answerKey[i] == 'T')
                ++t_cnt;
            else
                ++f_cnt;
            if (min(t_cnt, f_cnt) <= k)
                ++len;
            else if (answerKey[i - len] == 'T')
                --t_cnt;
            else
                --f_cnt;
        }
        return len;
    }

private:
    int maxConsecutiveAnswers(const string& answerKey, int k, char ch)
    {
        int res = 0;
        for (int l = 0, r = 0, s = 0; r < answerKey.size(); ++r) {
            s += answerKey[r] != ch;
            while (s > k)
                s -= answerKey[l++] != ch;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
