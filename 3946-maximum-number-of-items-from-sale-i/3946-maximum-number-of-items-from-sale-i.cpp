class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int max_f = 1500;
        vector<int> freq(max_f + 1, 0);
        int min_p = 1e9;
        
        for (auto& it : items) {
            freq[it[0]]++;
            min_p = min(min_p, it[1]);
        }
        
        vector<int> mult(max_f + 1, 0);
        for (int i = 1; i <= max_f; ++i) {
            if (freq[i] == 0) continue;
            for (int j = i; j <= max_f; j += i) {
                mult[i] += freq[j];
            }
        }
        
        vector<int> dp(budget + 1, 0);
        for (auto& it : items) {
            int val = mult[it[0]], cost = it[1];
            for (int w = budget; w >= cost; --w) {
                dp[w] = max(dp[w], dp[w - cost] + val);
            }
        }
        
        for (int w = min_p; w <= budget; ++w) {
            dp[w] = max(dp[w], dp[w - min_p] + 1);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};