class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int max = 0, count = 0;
        for (int[] rectangle : rectangles) {
            int side = Math.min(rectangle[0], rectangle[1]);
            if (max < side) {
                max = side;
                count = 1;
            } else if (max == side) {
                count++;
            }
        }
        return count;
    }
}
