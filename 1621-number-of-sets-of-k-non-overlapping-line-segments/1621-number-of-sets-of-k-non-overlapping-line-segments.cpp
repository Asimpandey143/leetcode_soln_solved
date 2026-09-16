class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long N = n + k - 1;
        long long R = 2 * k;

        if (R > N) return 0;

        // Calculate C(N, R) % MOD using modular multiplicative inverse
        long long num = 1, den = 1;
        for (long long i = 1; i <= R; ++i) {
            num = (num * (N - R + i)) % MOD;
            den = (den * i) % MOD;
        }

        // Fermat's Little Theorem for modular inverse of den
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        return (num * power(den, MOD - 2)) % MOD;
    }
};