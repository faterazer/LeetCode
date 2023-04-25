import java.util.Arrays;

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        Arrays.sort(indices, (i, j) -> heights[j] - heights[i]);
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = names[indices[i]];
        }
        return res;
    }
}
