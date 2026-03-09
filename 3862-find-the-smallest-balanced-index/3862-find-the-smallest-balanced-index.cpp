class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        
        vector<long double> suffixprod(n + 1, 1.0);
        for(int i = n-1; i >= 0 ;i--){
            suffixprod[i]= suffixprod[i + 1] * (long double)nums[i];

            if(suffixprod[i] > 1e16)
              suffixprod[i] = 1e16 +7;
        }
            long long leftsum = 0;
            for (int i = 0 ; i < n ; i++){
                if(suffixprod[i +1] <= 2e14){
                    if(leftsum == (long double)suffixprod[i + 1]){
                        return i;
                    }
                }
                leftsum += nums[i];
            }
            return -1;
            
    }
};