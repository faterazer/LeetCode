#include <math.h>

int helper(char* answerKey, int k, char ch)
{
    int l = 0, r = 0, sum = 0, res = 0;
    for (; answerKey[r]; ++r) {
        sum += answerKey[r] != ch;
        while (sum > k)
            sum -= answerKey[l++] != ch;
        res = fmax(res, r - l + 1);
    }
    return res;
}

int maxConsecutiveAnswers_MK1(char* answerKey, int k)
{
    return fmax(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
}

int maxConsecutiveAnswers_MK2(char* answerKey, int k)
{
    int t_cnt = 0, f_cnt = 0, len = 0;
    for (int i = 0; answerKey[i]; ++i) {
        if (answerKey[i] == 'T')
            t_cnt += 1;
        else
            f_cnt += 1;

        if (fmin(t_cnt, f_cnt) <= k)
            len += 1;
        else if (answerKey[i - len] == 'T')
            t_cnt -= 1;
        else
            f_cnt -= 1;
    }
    return len;
}
