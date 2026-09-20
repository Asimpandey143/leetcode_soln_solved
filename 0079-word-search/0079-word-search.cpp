#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, m, n)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index, int r, int c, int m, int n) {
        if (index == word.length()) return true;

        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark cell as visited

        // Explore 4 directional paths: down, up, right, left
        bool found = dfs(board, word, index + 1, r + 1, c, m, n) ||
                     dfs(board, word, index + 1, r - 1, c, m, n) ||
                     dfs(board, word, index + 1, r, c + 1, m, n) ||
                     dfs(board, word, index + 1, r, c - 1, m, n);

        board[r][c] = temp; // Unmark / Backtrack
        return found;
    }
};