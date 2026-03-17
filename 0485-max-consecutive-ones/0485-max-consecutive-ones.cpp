class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0;
        int maxi = 0;

        while(left < n){
            if(nums[left] == 1){
                sum++;
            }else if(nums[left] == 0){
                sum = 0;
            }
            maxi = max(maxi, sum);
            left++;

        }
        return maxi;
    }
};