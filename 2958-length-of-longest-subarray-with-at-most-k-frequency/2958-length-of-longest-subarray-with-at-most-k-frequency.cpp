#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Expand the window by adding nums[right]
            freq[nums[right]]++;
            
            // Shrink the window from the left if the frequency exceeds k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            // Update the maximum valid window length
            maxLen = std::max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};