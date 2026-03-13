class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left < right){
            //if(s[left] )
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};