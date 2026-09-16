class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {
            // Fill top row
            for (int col = left; col <= right; ++col) {
                matrix[top][col] = num++;
            }
            top++;

            // Fill right column
            for (int row = top; row <= bottom; ++row) {
                matrix[row][right] = num++;
            }
            right--;

            // Fill bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    matrix[bottom][col] = num++;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    matrix[row][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};