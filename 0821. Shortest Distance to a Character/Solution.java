class Solution {
    public int[] shortestToChar(String S, char C) {
        int[] res = new int[S.length()];
        int lastC = S.indexOf(C);
        for (int i = 0; i < lastC; i++)
            res[i] = lastC - i;
        for (int i = S.indexOf(C, lastC + 1); i >= 0; lastC = i, i = S.indexOf(C, lastC + 1)) {
            for (int j = lastC; j <= i; j++)
                res[j] = Math.min(j - lastC, i - j);
        }
        for (int i = lastC; i < res.length; i++)
            res[i] = i - lastC;
        return res;
    }
}
