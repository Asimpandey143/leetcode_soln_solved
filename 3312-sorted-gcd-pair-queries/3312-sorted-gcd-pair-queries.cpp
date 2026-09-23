class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        // Step 1: Count frequency of each number
        vector<long long> freq(max_val + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Count how many elements are multiples of each number
        vector<long long> multiple_counts(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            long long count = 0;
            for (int j = i; j <= max_val; j += i) {
                count += freq[j];
            }
            multiple_counts[i] = count * (count - 1) / 2;
        }

        // Step 3: Use inclusion-exclusion to find exact pairs for each GCD value
        vector<long long> exact_gcd_counts(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            exact_gcd_counts[i] = multiple_counts[i];
            for (int j = 2 * i; j <= max_val; j += i) {
                exact_gcd_counts[i] -= exact_gcd_counts[j];
            }
        }

        // Step 4: Build prefix sums of counts to map sorted order to GCD values
        vector<long long> prefix_counts(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix_counts[i] = prefix_counts[i - 1] + exact_gcd_counts[i];
        }

        // Step 5: Answer queries using binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            // q is 0-indexed, find the first GCD group index where prefix_counts > q
            auto it = upper_bound(prefix_counts.begin(), prefix_counts.end(), q);
            ans.push_back(distance(prefix_counts.begin(), it));
        }

        return ans;
    }
};