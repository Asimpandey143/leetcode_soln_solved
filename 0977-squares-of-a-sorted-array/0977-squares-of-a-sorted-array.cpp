class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i< n; i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
        
        // vector<int>res (n);
        // int l = 0;
        // int r = n-1;
        // int i = n;
        // while(l <= r){
        //     if(res[])

        // }

        
    }
};