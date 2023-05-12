import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int minPushBox(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] startState = new int[4];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') {
                    startState[0] = i;
                    startState[1] = j;
                } else if (grid[i][j] == 'S') {
                    startState[2] = i;
                    startState[3] = j;
                }
            }
        }

        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Deque<int[]> queue = new ArrayDeque<>();
        queue.push(startState);
        boolean[][][][] visited = new boolean[m][n][m][n];
        visited[startState[0]][startState[1]][startState[2]][startState[3]] = true;
        int pushes = 0;
        while (!queue.isEmpty()) {
            Deque<int[]> nextQueue = new ArrayDeque<>();
            while (!queue.isEmpty()) {
                int[] state = queue.pop();
                if (grid[state[0]][state[1]] == 'T') {
                    return pushes;
                }

                for (int[] direction : directions) {
                    int sr = state[2] + direction[0], sc = state[3] + direction[1];
                    if (sr < 0 || sr >= m || sc < 0 || sc >= n || grid[sr][sc] == '#') {
                        continue;
                    }
                    if (sr == state[0] && sc == state[1]) {
                        int br = state[0] + direction[0], bc = state[1] + direction[1];
                        if (br < 0 || br >= m || bc < 0 || bc >= n || grid[br][bc] == '#' || visited[br][bc][sr][sc]) {
                            continue;
                        }
                        visited[br][bc][sr][sc] = true;
                        nextQueue.push(new int[]{br, bc, sr, sc});
                    } else if (!visited[state[0]][state[1]][sr][sc]) {
                        visited[state[0]][state[1]][sr][sc] = true;
                        queue.push(new int[]{state[0], state[1], sr, sc});
                    }
                }
            }
            queue = nextQueue;
            ++pushes;
        }
        return -1;
    }
}
