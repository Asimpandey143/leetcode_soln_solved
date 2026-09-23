class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Handle small edge cases directly
        if (n == 1) return 1;
        if (n == 2) {
            // Permutation of [1, 2]
            // Triplets: (1^1^1 = 1), (1^1^2 = 2), (1^2^2 = 1), (2^2^2 = 2) -> {1, 2}
            return 2;
        }

        // Find the most significant bit (MSB) of n
        int msb = 0;
        while ((1 << (msb + 1)) <= n) {
            msb++;
        }

        // For n >= 3, the reachable unique XOR values span from 0 up to 2^(msb + 1) - 1
        return 1 << (msb + 1);
    }
};