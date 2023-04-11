class Solution {
    private final int[][] directions = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    public boolean isRobotBounded(String instructions) {
        int x = 0, y = 0, d = 0;
        for (int i = 0; i < instructions.length(); i++) {
            if (instructions.charAt(i) == 'R') {
                d = (d + 1) % 4;
            } else if (instructions.charAt(i) == 'L') {
                d = (d + 3) % 4;
            } else {
                x += directions[d][0];
                y += directions[d][1];
            }
        }
        return x == 0 && y == 0 || d > 0;
    }
}
