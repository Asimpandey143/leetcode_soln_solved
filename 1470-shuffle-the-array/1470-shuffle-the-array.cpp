class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int>result;

        int a = nums.size();
        int left = 0;
        int right = n;
        while(right < a){
            result.push_back(nums[left]);
            result.push_back(nums[right]);

            left++;
            right++;
        }
        return result;
    }
};