class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        
        // 1. Find the sum of the longest sequential prefix starting at index 0
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        
        // 2. Store elements in a hash set for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer >= sum
        while (st.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};