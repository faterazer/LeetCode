import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isPathCrossing(String path) {
        int x = 0, y = 0;
        Set<Integer> visited = new HashSet<>();
        visited.add(0);
        for (char c : path.toCharArray()) {
            if (c == 'N') {
                ++y;
            } else if (c == 'S') {
                --y;
            } else if (c == 'E') {
                ++x;
            } else {
                --x;
            }
            if (!visited.add(x * 100000 + y)) {
                return true;
            }
        }
        return false;
    }
}
