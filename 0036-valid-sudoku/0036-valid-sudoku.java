class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Track seen numbers for rows, columns, and 3x3 sub-boxes
        boolean[][] rows = new boolean[9][9];
        boolean[][] cols = new boolean[9][9];
        boolean[][] boxes = new boolean[9][9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue; // Skip empty cells
                }

                int num = board[r][c] - '1'; // Convert char '1'-'9' to index 0-8
                int boxIndex = (r / 3) * 3 + (c / 3); // Map (r, c) to box index 0-8

                // Check if number has already been seen in the row, column, or 3x3 box
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                    return false;
                }

                // Mark number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[boxIndex][num] = true;
            }
        }

        return true;
    }
}