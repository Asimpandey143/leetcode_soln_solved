class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int num = n.size();
        int i = 0;
        int j = num -1;

        while( i < j){
            int sum = n[i] + n[j];
            if(sum == target){ 
                return {i+1, j+1};
            }else if(sum < target){
                i++;
            }else {
                j--;

            }

        }
        return {};

        
    }
};