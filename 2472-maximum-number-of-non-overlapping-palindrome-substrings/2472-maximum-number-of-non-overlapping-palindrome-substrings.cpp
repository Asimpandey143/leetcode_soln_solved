class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        // dp[i] stores the max palindromes in prefix of length i
        vector dp(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            
            // Try expanding for odd length palindromes centered at i
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    // Once we find the shortest valid palindrome starting at 'l',
                    // greedily breaking early helps because further expansions 
                    // only increase length without adding more non-overlapping items here.
                    break; 
                }
                l--;
                r++;
            }

            // Try expanding for even length palindromes centered between i and i+1
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break;
                }
                l--;
                r++;
            }
        }

        return dp[n];
    }
};