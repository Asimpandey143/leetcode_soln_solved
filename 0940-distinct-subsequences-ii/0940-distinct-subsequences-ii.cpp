class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> last(26, 0);
        long long mod = 1e9 + 7;
        for (char c : s) {
            long long sum = 0;
            for (long long x : last) sum = (sum + x) % mod;
            last[c - 'a'] = (sum + 1) % mod;
        }
        long long ans = 0;
        for (long long x : last) ans = (ans + x) % mod;
        return ans;
    }
};