class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // dp[i] stores the minimum cost to reach step i
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int min_cost = INT_MAX;
            
            // Can come from step i-1 (1 step jump: cost (1)^2 = 1)
            if (i - 1 >= 0) {
                min_cost = min(min_cost, dp[i - 1] + 1);
            }
            // Can come from step i-2 (2 step jump: cost (2)^2 = 4)
            if (i - 2 >= 0) {
                min_cost = min(min_cost, dp[i - 2] + 4);
            }
            // Can come from step i-3 (3 step jump: cost (3)^2 = 9)
            if (i - 3 >= 0) {
                min_cost = min(min_cost, dp[i - 3] + 9);
            }

            // costs is 1-indexed, so costs[i - 1] corresponds to step i
            dp[i] = min_cost + costs[i - 1];
        }

        return dp[n];
    }
};