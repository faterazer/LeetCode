import java.util.Arrays;

class Solution {
    public int uniqueLetterString(String s) {
        int[][] indices = new int[26][2];
        for (int[] arr : indices) {
            Arrays.fill(arr, -1);
        }

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'A';
            res += (indices[index][1] - indices[index][0]) * (i - indices[index][1]);
            indices[index][0] = indices[index][1];
            indices[index][1] = i;
        }
        for (int i = 0; i < 26; i++) {
            res += (indices[i][1] - indices[i][0]) * (s.length() - indices[i][1]);
        }
        return res;
    }
}
