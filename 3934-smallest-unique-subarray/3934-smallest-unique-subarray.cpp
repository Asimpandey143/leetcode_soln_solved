#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Two distinct large primes and bases for collision-resistant double hashing
        const long long MOD1 = 1e9 + 7, BASE1 = 1315423911;
        const long long MOD2 = 1e9 + 9, BASE2 = 2654435761;
        
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
        }
        
        auto hasUnique = [&](int len) -> bool {
            unordered_map<uint64_t, int> freq;
            freq.reserve(n - len + 1);
            
            for (int i = 0; i <= n - len; ++i) {
                long long sub1 = (h1[i + len] - (h1[i] * p1[len]) % MOD1 + MOD1) % MOD1;
                long long sub2 = (h2[i + len] - (h2[i] * p2[len]) % MOD2 + MOD2) % MOD2;
                
                // Combine both 32-bit hashes into a single 64-bit key
                uint64_t key = (static_cast<uint64_t>(sub1) << 32) | static_cast<uint64_t>(sub2);
                freq[key]++;
            }
            
            for (const auto& [key, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };
        
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};