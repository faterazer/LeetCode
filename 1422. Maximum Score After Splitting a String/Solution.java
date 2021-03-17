class Solution {
    public int maxScore(String s) {
        int leftSum = 0, rightSum = 0, res;
        if (s.charAt(0) == '0') {
            leftSum++;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                rightSum++;
            }
        }
        res = leftSum + rightSum;
        for (int i = 1; i < s.length() - 1; i++) {
            if (s.charAt(i) == '0') {
                leftSum++;
            } else {
                rightSum--;
            }
            res = Math.max(res, leftSum + rightSum);
        }
        return res;
    }
}
