class Solution {
    public int beautySum(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int[] count = new int[26];
            for (int j = i; j < s.length(); j++) {
                ++count[s.charAt(j) - 'a'];
                int max = 0, min = Integer.MAX_VALUE;
                for (int x : count) {
                    max = Math.max(max, x);
                    if (x > 0) {
                        min = Math.min(min, x);
                    }
                }
                res += max - min;
            }
        }
        return res;
    }
}
