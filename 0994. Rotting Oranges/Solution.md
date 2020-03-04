# Solution

## Approach 1: Breadth-First Search

### Intuition

Every turn, the rotting spreads from each rotting orange to other adjacent oranges. Initially, the rotten oranges have 'depth' 0 [as in the spanning tree of a graph], and every time they rot a neighbor, the neighbors have 1 more depth. We want to know the largest possible depth.

### Algorithm

We can use a breadth-first search to model this process. Because we always explore nodes (oranges) with the smallest depth first, we're guaranteed that each orange that becomes rotten does so with the lowest possible depth number.

We should also check that at the end, there are no fresh oranges left.

**Java:**

```java
class Solution {
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};

    public int orangesRotting(int[][] grid) {
        int R = grid.length, C = grid[0].length;

        // queue : all starting cells with rotten oranges
        Queue<Integer> queue = new ArrayDeque();
        Map<Integer, Integer> depth = new HashMap();
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                if (grid[r][c] == 2) {
                    int code = r * C + c;
                    queue.add(code);
                    depth.put(code, 0);
                }

        int ans = 0;
        while (!queue.isEmpty()) {
            int code = queue.remove();
            int r = code / C, c = code % C;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    int ncode = nr * C + nc;
                    queue.add(ncode);
                    depth.put(ncode, depth.get(code) + 1);
                    ans = depth.get(ncode);
                }
            }
        }

        for (int[] row: grid)
            for (int v: row)
                if (v == 1)
                    return -1;
        return ans;

    }
}
```

**Python:**

```python
class Solution(object):
    def orangesRotting(self, grid):
        R, C = len(grid), len(grid[0])

        # queue - all starting cells with rotting oranges
        queue = collections.deque()
        for r, row in enumerate(A):
            for c, val in enumerate(row):
                if val == 2:
                    queue.append((r, c, 0))

        def neighbors(r, c):
            for nr, nc in ((r-1,c),(r,c-1),(r+1,c),(r,c+1)):
                if 0 <= nr < R and 0 <= nc < C:
                    yield nr, nc

        d = 0
        while queue:
            r, c, d = queue.popleft()
            for nr, nc in neighbors(r, c):
                if A[nr][nc] == 1:
                    A[nr][nc] = 2
                    queue.append((nr, nc, d+1))

        if any(1 in row for row in A):
            return -1
        return d
```

### Complexity Analysis

* Time Complexity: $O(N)$, where $N$ is the number of cells in the grid.
* Space Complexity: $O(N)$.
