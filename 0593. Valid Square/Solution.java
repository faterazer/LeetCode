import java.util.Arrays;

class Solution {
    private int distance(int[] p1, int[] p2) {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int[] sideLens = new int[]{
                distance(p1, p2), distance(p1, p3), distance(p1, p4),
                distance(p2, p3), distance(p2, p4), distance(p3, p4)
        };
        Arrays.sort(sideLens);
        return sideLens[0] == sideLens[3] && sideLens[3] != sideLens[4] && sideLens[4] == sideLens[5];
    }
}
