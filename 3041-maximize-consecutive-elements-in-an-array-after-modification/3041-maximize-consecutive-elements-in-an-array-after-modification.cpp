class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // Max element is 10^6, plus 1 for the +1 modification, plus buffer
        vector<int> dp(1000005, 0);
        int max_len = 0;
        
        for (int x : nums) {
            // Update x + 1 first so we don't reuse the same element twice
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            
            max_len = max({max_len, dp[x], dp[x + 1]});
        }
        
        return max_len;
    }
};