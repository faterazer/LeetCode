class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int d1 = 0, d2 = 0;
        for (int i = start; i != destination; i = (i + 1) % distance.length) {
            d1 += distance[i];
        }
        for (int i = destination; i != start; i = (i + 1) % distance.length) {
            d2 += distance[i];
        }
        return Math.min(d1, d2);
    }
}
