class Solution {
    public int candy(int[] ratings) {
        int dec = 0, inc = 1, res = 1, pre = 1;
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                inc = pre;
                res += pre;
            } else {
                ++dec;
                if (dec == inc) {
                    ++dec;
                }
                pre = 1;
                res += dec;
            }
        }
        return res;
    }
}
