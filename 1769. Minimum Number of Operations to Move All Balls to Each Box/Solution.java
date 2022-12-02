class Solution {
    public int[] minOperations(String boxes) {
        int lcnt = 0, rcnt = 0, state = 0;
        for (int i = 0; i < boxes.length(); i++) {
            if (boxes.charAt(i) == '1') {
                state += i;
                ++rcnt;
            }
        }

        int[] res = new int[boxes.length()];
        for (int i = 0; i < res.length; i++) {
            res[i] = state;
            if (boxes.charAt(i) == '1') {
                ++lcnt;
                --rcnt;
            }
            state += lcnt - rcnt;
        }
        return res;
    }
}
