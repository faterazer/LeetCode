class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int[] f = new int[books.length + 1];
        for (int i = 0; i < books.length; i++) {
            int thickness = books[i][0], height = books[i][1];
            f[i + 1] = f[i] + height;
            for (int j = i - 1; j >= 0 && thickness + books[j][0] <= shelfWidth; j--) {
                thickness += books[j][0];
                height = Math.max(height, books[j][1]);
                f[i + 1] = Math.min(f[i + 1], height + f[j]);
            }
        }
        return f[books.length];
    }
}
