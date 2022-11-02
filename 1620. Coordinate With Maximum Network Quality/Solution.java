class Solution {
    public int[] bestCoordinate(int[][] towers, int radius) {
        int xMin = 0, xMax = 0, yMin = 0, yMax = 0;
        for (int[] tower : towers) {
            xMin = Math.min(xMin, tower[0]);
            xMax = Math.max(xMax, tower[0]);
            yMin = Math.min(yMin, tower[1]);
            yMax = Math.max(yMax, tower[1]);
        }

        int[] res = new int[2];
        int maxQuality = 0;
        for (int x = xMin; x <= xMax; x++) {
            for (int y = yMin; y <= yMax; y++) {
                int quality = 0;
                for (int[] tower : towers) {
                    int d2 = (x - tower[0]) * (x - tower[0]) + (y - tower[1]) * (y - tower[1]);
                    if (d2 <= radius * radius) {
                        quality += Math.floor(tower[2] / (1.0 + Math.sqrt(d2)));
                    }
                }
                if (quality > maxQuality) {
                    maxQuality = quality;
                    res[0] = x;
                    res[1] = y;
                }
            }
        }
        return res;
    }
}
