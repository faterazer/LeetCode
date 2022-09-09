import java.util.Arrays;

class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        Arrays.sort(properties, (a, b) -> a[0] != b[0] ? b[0] - a[0] : a[1] - b[1]);
        int maxDef = 0, res = 0;
        for (int[] property : properties) {
            if (property[1] < maxDef) {
                ++res;
            } else {
                maxDef = property[1];
            }
        }
        return res;
    }
}
