#include <algorithm>

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;
        
        // Option 1: Buy type 3 for min(n1, n2), then buy individual/cheapest for the rest
        long long common = std::min(n1, n2);
        long long rem1 = n1 - common;
        long long rem2 = n2 - common;
        
        long long ans1 = common * cb + rem1 * std::min(c1, cb) + rem2 * std::min(c2, cb);
        
        // Option 2: Buy type 3 for max(n1, n2) to fulfill everything
        long long ans2 = std::max(n1, n2) * cb;
        
        // Option 3: Fulfill need1 and need2 completely using separate items
        long long ans3 = n1 * c1 + n2 * c2;
        
        return std::min({ans1, ans2, ans3});
    }
};