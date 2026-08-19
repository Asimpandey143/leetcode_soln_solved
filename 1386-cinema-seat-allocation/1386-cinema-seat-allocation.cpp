#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map row number to a bitmask of reserved seats (focusing on seats 2 to 9)
        unordered_map<int, int> rowMask;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                rowMask[row] |= (1 << (col - 2)); // Shift into bits 0..7
            }
        }

        // Each unreserved row can seat 2 families
        int totalFamilies = (n - rowMask.size()) * 2;

        // Bitmasks for the 3 possible seating blocks:
        // Seats 2, 3, 4, 5 -> bits 0, 1, 2, 3 -> (1 | 2 | 4 | 8) = 0b00001111 (15)
        // Seats 6, 7, 8, 9 -> bits 4, 5, 6, 7 -> (16 | 32 | 64 | 128) = 0b11110000 (240)
        // Seats 4, 5, 6, 7 -> bits 2, 3, 4, 5 -> (4 | 8 | 16 | 32) = 0b00111100 (60)
        const int leftMask   = 0b00001111;
        const int rightMask  = 0b11110000;
        const int middleMask = 0b00111100;

        for (const auto& [row, mask] : rowMask) {
            bool left   = (mask & leftMask) == 0;
            bool right  = (mask & rightMask) == 0;
            bool middle = (mask & middleMask) == 0;

            if (left && right) {
                totalFamilies += 2;
            } else if (left || right || middle) {
                totalFamilies += 1;
            }
        }

        return totalFamilies;
    }
};