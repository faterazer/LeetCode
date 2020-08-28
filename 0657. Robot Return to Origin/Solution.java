class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0, y = 0;
        for (char move : moves.toCharArray()) {
            switch (move) {
                case 'U' -> x++;
                case 'D' -> x--;
                case 'R' -> y++;
                case 'L' -> y--;
            }
        }
        return x == 0 && y == 0;
    }
}
