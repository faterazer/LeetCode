import java.util.*;

class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        List<Integer> A = new ArrayList<>();
        List<Integer> B = new ArrayList<>();
        for (int i = 0; i < img1.length; i++) {
            for (int j = 0; j < img1[i].length; j++) {
                if (img1[i][j] == 1) {
                    A.add(i * 100 + j);
                }
            }
        }
        for (int i = 0; i < img2.length; i++) {
            for (int j = 0; j < img2[i].length; j++) {
                if (img2[i][j] == 1) {
                    B.add(i * 100 + j);
                }
            }
        }

        Map<Integer, Integer> count = new HashMap<>();
        for (Integer x : A) {
            for (Integer y : B) {
                count.put(x - y, count.getOrDefault(x - y, 0) + 1);
            }
        }
        int res = 0;
        for (Integer value : count.values()) {
            res = Math.max(res, value);
        }
        return res;
    }
}
