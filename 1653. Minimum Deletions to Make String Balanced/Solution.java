class Solution {
    public int minimumDeletions_MK1(String s) {
        int del = 0;
        for (int i = 0; i < s.length(); i++) {
            del += 'b' - s.charAt(i);
        }

        int res = del;
        for (int i = 0; i < s.length(); i++) {
            del += (s.charAt(i) - 'a') * 2 - 1;
            res = Math.min(res, del);
        }
        return res;
    }

    public int minimumDeletions_MK2(String s) {
        int res = 0, countB = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') {
                res = Math.min(res + 1, countB);
            } else {
                ++countB;
            }
        }
        return res;
    }
}
