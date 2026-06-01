class Solution {
public:
    int digitFrequencyScore(int n) {
        int f[10] = {0};

        while (n > 0) {
            int d = n%10;
            f[d]++;
            n /= 10;
        }

        int s = 0;
        for(int d = 0;d <=9; d++){
            if(f[d] > 0){
                s += d * f[d];
            }
        }
        return s;
        
    }
};