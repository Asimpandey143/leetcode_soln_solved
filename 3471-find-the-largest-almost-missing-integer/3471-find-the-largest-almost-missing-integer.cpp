#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> subarray_count;

        // Count how many subarrays of size k contain each number
        for (int i = 0; i <= n - k; ++i) {
            std::unordered_set<int> unique_in_window(nums.begin() + i, nums.begin() + i + k);
            for (int val : unique_in_window) {
                subarray_count[val]++;
            }
        }

        int max_val = -1;
        for (const auto& [val, count] : subarray_count) {
            if (count == 1) {
                max_val = std::max(max_val, val);
            }
        }

        return max_val;
    }
};