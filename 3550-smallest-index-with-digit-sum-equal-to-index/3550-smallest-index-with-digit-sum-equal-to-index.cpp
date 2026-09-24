class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int digitSum = 0;
            int temp = nums[i];
            
            // Handle negative numbers just in case, though constraints say 0 <= nums[i] <= 1000
            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }
            
            // If nums[i] is 0, its digit sum is 0
            if (nums[i] == 0 && i == 0) return 0;
            
            if (digitSum == i) {
                return i;
            }
        }
        return -1;
    }
};