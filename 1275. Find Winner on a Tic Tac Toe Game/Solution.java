class Solution {
    public String tictactoe(int[][] moves) {
        int[] row = new int[3], col = new int[3], dia = new int[2];
        for (int i = 0; i < moves.length; i++) {
            int[] m = moves[i];
            if (i % 2 == 0) {
                if (++row[m[0]] == 3 || ++col[m[1]] == 3 || (m[0] == m[1] && ++dia[0] == 3) || (m[0] + m[1] == 2 && ++dia[1] == 3))
                    return "A";
            } else {
                if (--row[m[0]] == -3 || --col[m[1]] == -3 || (m[0] == m[1] && --dia[0] == -3) || (m[0] + m[1] == 2 && --dia[1] == -3))
                    return "B";
            }
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }
}
