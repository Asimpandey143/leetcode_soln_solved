class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            if(nums[left] == target && nums[right] == target){
                return {left, right};

            }else if(nums[left] < target){
                left++;
            }else if (nums[right] > target){
                right--;
            }
        }
        return {-1, -1};
    }
};