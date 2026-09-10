class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Target cannot be formed if totalSum < Math.abs(target) 
        // or if (totalSum + target) is odd
        if (Math.abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (totalSum + target) / 2;

        // DP array to count subsets that sum to subsetSum
        int[] dp = new int[subsetSum + 1];
        dp[0] = 1; // Base case: 1 way to get sum 0 (empty subset)

        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
}