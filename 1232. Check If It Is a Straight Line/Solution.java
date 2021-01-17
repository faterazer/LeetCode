class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int A = coordinates[1][1] - coordinates[0][1];
        int B = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.length; i++) {
            if ((coordinates[i][1] - coordinates[0][1]) * B != (coordinates[i][0] - coordinates[0][0]) * A)
                return false;
        }
        return true;
    }
}
