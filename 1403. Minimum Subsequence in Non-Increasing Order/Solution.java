import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        int sum1 = 0, sum2 = 0;
        int[] hash = new int[101];
        for (int x : nums) {
            hash[x]++;
            sum2 += x;
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 100; i > 0; i--) {
            while (hash[i]-- > 0) {
                res.add(i);
                sum1 += i;
                sum2 -= i;
                if (sum1 > sum2) return res;
            }
        }
        return null;
    }
}
