class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long r = k, c = 0, o =0, MOD = 1e9 + 7;
        for(int x : nums){
            if(r < x){
                long long req = (x - r + k - 1) / k;
                long long start = o + 1;
                long long end = o + req;
                long long sum = (unsigned __int128)(start +end ) * req / 2 % MOD;
                c = (c + sum) % MOD;
                o += req;
                r += (unsigned __int128)req * k;
            }
            r  -= x;
        }
        return c;
    }
};