class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        
        // Precompute valid proper divisors for every possible substring length
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }
        
        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_ops = INF;
                
                for (int d : divisors[len]) {
                    int ops = 0;
                    // Check each of the d interleaved groups
                    for (int start = 0; start < d; ++start) {
                        int left = i + start;
                        int right = j - (d - 1 - start);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                ops++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_ops = min(min_ops, ops);
                }
                cost[i][j] = min_ops;
            }
        }
        
        // dp[i][p] = min changes to split s[0..i-1] into p semi-palindromes
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            for (int i = 2 * p; i <= n; ++i) {
                for (int j = 2 * (p - 1); j <= i - 2; ++j) {
                    if (dp[j][p - 1] != INF) {
                        dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};