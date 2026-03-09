class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int num = n.size();
        int l = 0;
        int r = num -1;

        while( l < r){
            int sum = n[l] + n[r];
            if(sum == target){ 
                return {l+1, r+1};
            }else if(sum < target){
                l++;
            }else {
                r--;

            }

        }
        return {};

        
    }
};