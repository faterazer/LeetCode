class Solution {
    public boolean winnerOfGame(String colors) {
        int Alice_count = 0, Bob_count = 0;
        for (int i = 1; i < colors.length() - 1; ++i) {
            if (colors.charAt(i - 1) == colors.charAt(i) && colors.charAt(i) == colors.charAt(i + 1)) {
                if (colors.charAt(i) == 'A') {
                    Alice_count += 1;
                } else {
                    Bob_count += 1;
                }
            }
        }
        return Alice_count > Bob_count;
    }
}
