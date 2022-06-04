import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        List<String> board = new ArrayList<>();
        helper(board, n, 0, 0, 0, res);
        return res;
    }

    private void helper(List<String> board, int n, int col_used, int dia1_used, int dia2_used, List<List<String>> res) {
        if (board.size() == n) {
            res.add(new ArrayList<>(board));
            return;
        }
        char[] line = new char[n];
        Arrays.fill(line, '.');
        int pos = 1 << n;
        for (int i = 0; i < n; ++i) {
            pos >>= 1;
            if ((col_used & pos) == 0 && (dia1_used & pos) == 0 && (dia2_used & pos) == 0) {
                line[i] = 'Q';
                board.add(new String(line));
                helper(board, n, col_used | pos, (dia1_used | pos) << 1, (dia2_used | pos) >> 1, res);
                board.remove(board.size() - 1);
                line[i] = '.';
            }
        }
    }
}
