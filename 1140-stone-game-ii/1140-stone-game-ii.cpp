class Solution {
public:
    int memo[101][101];
    
    int solve(int i, int M, vector<int>& piles, vector<int>& suffixSum) {
        int n = piles.size();
        
        // If remaining piles can all be taken, take all of them
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        
        if (memo[i][M] != -1) {
            return memo[i][M];
        }
        
        int minOpponentStones = INT_MAX;
        
        // Try taking X piles (1 <= X <= 2 * M)
        for (int X = 1; X <= 2 * M; X++) {
            int nextM = max(M, X);
            minOpponentStones = min(minOpponentStones, solve(i + X, nextM, piles, suffixSum));
        }
        
        // Max stones current player can get = Total remaining stones - Min opponent stones
        return memo[i][M] = suffixSum[i] - minOpponentStones;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(memo, -1, sizeof(memo));
        
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        return solve(0, 1, piles, suffixSum);
    }
};