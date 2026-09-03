class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        for (int x : nums1){
            if(x < min_val) min_val = x;  
        
        }
    if(min_val % 2 != 0){
    return true;
    }
    for(int x : nums1){
        if(x % 2 != 0)return false;    
    }
        return true;
    }
};