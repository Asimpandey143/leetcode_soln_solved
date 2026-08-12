#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Deals with patterns like a*, a*b*, or a*b*c* matching empty string
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // Match single character
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // Two cases for '*':
                    // 1. Treat '*' as matching 0 occurrences of the preceding element -> dp[i][j - 2]
                    // 2. Treat '*' as matching 1+ occurrences if preceding char matches s[i-1] -> dp[i - 1][j]
                    dp[i][j] = dp[i][j - 2];
                    
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};