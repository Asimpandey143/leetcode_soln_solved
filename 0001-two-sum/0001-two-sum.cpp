/* // ONLY FOR SORTED ARRAY
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int a = 0;
        int b = n-1;

        while(a < b){
            int sum = nums[a] + nums[b];
            if(sum == target){
                return{a , b };
            }
            else if(sum < target){
                a++;
            }
            else{
                b--;
            }
        }
        return {};
    }
};
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j =i +1; j<n;j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
