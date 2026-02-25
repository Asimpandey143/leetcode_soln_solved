class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int last = m+n -1;
        int i = m-1;
        int j = n-1;
        while(i >= 0 && j>=0) {
            if( a[i] >= b[j]){
                a[last] = a[i];
                last--;
                i--;
            }else{
                a[last] = b[j];
                last--;
                j--;
            }
        }
        while(j >= 0){
            a[last] = b[j];
            last--;
            j--;
        }
    }
};