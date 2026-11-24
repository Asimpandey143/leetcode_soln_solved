#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1; // Any subarray of length 2 is always valid (a*b = gcd(a,b)*lcm(a,b))
        
        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            int l = 1;
            
            for (int j = i; j < n; ++j) {
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                
                if (prod == (long long)l * g) {
                    maxLen = max(maxLen, j - i + 1);
                }
                
                // Max possible LCM for numbers <= 10 is 2520, max GCD is 10.
                // Prevent overflow by stopping once prod exceeds the max possible RHS.
                if (prod > 25200) {
                    break;
                }
            }
        }
        
        return maxLen;
    }
};