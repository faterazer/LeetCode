import java.util.HashSet;
import java.util.Set;
import java.util.stream.IntStream;

class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int diff = (IntStream.of(A).sum() - IntStream.of(B).sum()) / 2;
        Set<Integer> set = new HashSet<>();
        for (int x : B) {
            set.add(x);
        }
        for (int x : A) {
            if (set.contains(x - diff)) {
                return new int[]{x, x - diff};
            }
        }
        return null;
    }
}
