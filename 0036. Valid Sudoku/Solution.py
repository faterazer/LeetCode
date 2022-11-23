from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows, cols, sub_boxes = [0] * 9, [0] * 9, [0] * 9
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue
                num_bit = 1 << int(board[i][j])
                sub_box_idx = i // 3 * 3 + j // 3
                if rows[i] & num_bit or cols[j] & num_bit or sub_boxes[sub_box_idx] & num_bit:
                    return False
                rows[i] |= num_bit
                cols[j] |= num_bit
                sub_boxes[sub_box_idx] |= num_bit
        return True
