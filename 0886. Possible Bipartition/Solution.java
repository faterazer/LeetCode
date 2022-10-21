import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    enum COLOR {
        WHITE, BLUE, RED
    }

    private boolean colorize(List<COLOR> colorMap, int i, COLOR color, Map<Integer, List<Integer>> graph) {
        colorMap.set(i, color);
        COLOR neighbourColor = color == COLOR.BLUE ? COLOR.RED : COLOR.BLUE;
        if (!graph.containsKey(i)) {
            return false;
        }
        for (Integer neighbour : graph.get(i)) {
            if (colorMap.get(neighbour) == color) {
                return true;
            }
            if (colorMap.get(neighbour) == COLOR.WHITE && colorize(colorMap, neighbour, neighbourColor, graph)) {
                return true;
            }
        }
        return false;
    }

    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<COLOR> colorMap = new ArrayList<>();
        for (int i = 0; i < n + 1; i++) {
            colorMap.add(COLOR.WHITE);
        }

        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] dislike : dislikes) {
            int a = dislike[0], b = dislike[1];
            graph.computeIfAbsent(a, key -> new ArrayList<>()).add(b);
            graph.computeIfAbsent(b, key -> new ArrayList<>()).add(a);
        }

        for (int i = 1; i <= n; i++) {
            if (colorMap.get(i) == COLOR.WHITE && colorize(colorMap, i, COLOR.RED, graph)) {
                return false;
            }
        }
        return true;
    }
}
