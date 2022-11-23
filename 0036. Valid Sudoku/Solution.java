class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] rows = new int[9], cols = new int[9], sub_boxes = new int[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num_bit = 1 << (board[i][j] - '0');
                int sub_box_idx = i / 3 * 3 + j / 3;
                if ((rows[i] & num_bit) != 0 || (cols[j] & num_bit) != 0 || (sub_boxes[sub_box_idx] & num_bit) != 0) {
                    return false;
                }
                rows[i] |= num_bit;
                cols[j] |= num_bit;
                sub_boxes[sub_box_idx] |= num_bit;
            }
        }
        return true;
    }
}
