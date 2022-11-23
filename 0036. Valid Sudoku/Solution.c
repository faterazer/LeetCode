#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int rows[9] = { 0 }, cols[9] = { 0 }, sub_boxes[9] = { 0 };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;
            int num_bit = 1 << (board[i][j] - '0');
            if (rows[i] & num_bit || cols[j] & num_bit || sub_boxes[i / 3 * 3 + j / 3] & num_bit)
                return false;
            rows[i] |= num_bit;
            cols[j] |= num_bit;
            sub_boxes[i / 3 * 3 + j / 3] |= num_bit;
        }
    }
    return true;
}
