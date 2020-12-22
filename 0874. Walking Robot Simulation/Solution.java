import java.util.HashSet;
import java.util.Set;

class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int[][] dirs = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int idx = 1;
        Set<String> set = new HashSet<>();
        for (int[] obstacle : obstacles) {
            set.add(obstacle[0] + " " + obstacle[1]);
        }
        int res = 0, x = 0, y = 0;
        for (int command : commands) {
            if (command == -1) {
                idx = (idx + 1) % dirs.length;
            } else if (command == -2) {
                idx = (idx + 3) % dirs.length;
            }else {
                for (int i = 0; i < command; i++) {
                    int nx = x + dirs[idx][0];
                    int ny = y + dirs[idx][1];
                    if (set.contains(nx + " " + ny))
                        break;
                    x = nx;
                    y = ny;
                }
                res = Math.max(res, x * x + y * y);
            }
        }
        return res;
    }
}
