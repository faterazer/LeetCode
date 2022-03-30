class Solution {
    private int maxConsecutiveAnswers(String answerKey, int k, char ch) {
        int res = 0;
        for (int left = 0, right = 0, sum = 0; right < answerKey.length(); ++right) {
            sum += answerKey.charAt(right) != ch ? 1 : 0;
            while (sum > k) {
                sum -= answerKey.charAt(left++) != ch ? 1 : 0;
            }
            res = Math.max(res, right - left + 1);
        }
        return res;
    }

    public int maxConsecutiveAnswers_MK1(String answerKey, int k) {
        return Math.max(maxConsecutiveAnswers(answerKey, k, 'T'), maxConsecutiveAnswers(answerKey, k, 'F'));
    }

    public int maxConsecutiveAnswers_MK2(String answerKey, int k) {
        int tCount = 0, fCount = 0, len = 0;
        for (int i = 0; i < answerKey.length(); ++i) {
            if (answerKey.charAt(i) == 'T') {
                tCount += 1;
            } else {
                fCount += 1;
            }
            if (Math.min(tCount, fCount) <= k) {
                len += 1;
            } else {
                if (answerKey.charAt(i - len) == 'T') {
                    tCount -= 1;
                } else {
                    fCount -= 1;
                }
            }
        }
        return len;
    }
}
