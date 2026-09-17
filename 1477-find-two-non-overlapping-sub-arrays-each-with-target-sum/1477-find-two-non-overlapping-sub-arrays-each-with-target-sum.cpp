#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // dp[i] stores the min length of a sub-array with sum == target ending at or before index i
        vector<int> dp(n, INT_MAX / 2); 
        
        int left = 0, current_sum = 0;
        int ans = INT_MAX / 2;
        int best_so_far = INT_MAX / 2;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            // Shrink window while sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }

            // Found a valid sub-array ending at `right`
            if (current_sum == target) {
                int curr_len = right - left + 1;

                // Check if there is a non-overlapping valid sub-array to the left
                if (left > 0 && dp[left - 1] != INT_MAX / 2) {
                    ans = min(ans, curr_len + dp[left - 1]);
                }

                best_so_far = min(best_so_far, curr_len);
            }

            // Record the minimum valid sub-array length up to index `right`
            dp[right] = best_so_far;
            if (right > 0) {
                dp[right] = min(dp[right], dp[right - 1]);
            }
        }

        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};