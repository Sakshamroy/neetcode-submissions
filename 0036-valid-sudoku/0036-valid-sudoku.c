#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // Bitmasks to track digits 1-9 for rows, columns, and 3x3 boxes
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char ch = board[r][c];
            if (ch == '.') {
                continue;
            }

            // Map '1'-'9' to bit position 0-8
            int val = ch - '1';
            int mask = 1 << val;
            int boxIdx = (r / 3) * 3 + (c / 3);

            // Check if digit has already appeared in row, column, or 3x3 box
            if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIdx] & mask)) {
                return false;
            }

            // Mark digit as seen
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[boxIdx] |= mask;
        }
    }

    return true;
}