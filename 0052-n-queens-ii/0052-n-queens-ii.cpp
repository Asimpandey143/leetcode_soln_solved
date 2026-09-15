class Solution {
private:
    void solve(int row, int n, int& count,
               vector<bool>& cols, vector<bool>& mainDiag, vector<bool>& antiDiag) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1; // Main diagonal index
            int d2 = row + col;         // Anti-diagonal index

            if (cols[col] || mainDiag[d1] || antiDiag[d2]) continue;

            // Place queen
            cols[col] = mainDiag[d1] = antiDiag[d2] = true;

            solve(row + 1, n, count, cols, mainDiag, antiDiag);

            // Backtrack
            cols[col] = mainDiag[d1] = antiDiag[d2] = false;
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);
        vector<bool> mainDiag(2 * n - 1, false);
        vector<bool> antiDiag(2 * n - 1, false);

        solve(0, n, count, cols, mainDiag, antiDiag);
        return count;
    }
};