class Solution {
private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result,
               vector<bool>& cols, vector<bool>& mainDiag, vector<bool>& antiDiag) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1; // Main diagonal index
            int d2 = row + col;         // Anti-diagonal index

            if (cols[col] || mainDiag[d1] || antiDiag[d2]) continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = mainDiag[d1] = antiDiag[d2] = true;

            solve(row + 1, n, board, result, cols, mainDiag, antiDiag);

            // Backtrack
            board[row][col] = '.';
            cols[col] = mainDiag[d1] = antiDiag[d2] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> mainDiag(2 * n - 1, false);
        vector<bool> antiDiag(2 * n - 1, false);

        solve(0, n, board, result, cols, mainDiag, antiDiag);
        return result;
    }
};