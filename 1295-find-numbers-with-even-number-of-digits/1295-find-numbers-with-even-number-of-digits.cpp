class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int count = 0;

        for(int n : nums){
            int digit = 0;
            while(n > 0){
                digit++;
                n /= 10;
            }
            if(digit% 2 == 0){
                count++;
            }
        }
        return count;
    }
};