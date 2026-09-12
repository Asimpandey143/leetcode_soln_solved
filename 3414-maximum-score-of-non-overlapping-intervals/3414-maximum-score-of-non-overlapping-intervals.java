import java.util.*;

class Solution {
    public int[] maximumWeight(List<List<Integer>> intervalsList) {
        int n = intervalsList.size();
        
        // Store interval with original index: [l, r, weight, origIndex]
        int[][] intervals = new int[n][4];
        for (int i = 0; i < n; i++) {
            List<Integer> interval = intervalsList.get(i);
            intervals[i][0] = interval.get(0);
            intervals[i][1] = interval.get(1);
            intervals[i][2] = interval.get(2);
            intervals[i][3] = i;
        }

        // Sort by right endpoint r ascending
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        // Extract right endpoints for binary search
        int[] rightEnds = new int[n];
        for (int i = 0; i < n; i++) {
            rightEnds[i] = intervals[i][1];
        }

        // dp[r][i] stores the best state after considering first i intervals with r chosen intervals.
        // State: max weight sum, and list of chosen original indices.
        State[][] dp = new State[5][n + 1];

        // Base cases
        for (int r = 0; r <= 4; r++) {
            for (int i = 0; i <= n; i++) {
                dp[r][i] = new State(0, new ArrayList<>());
            }
        }

        for (int i = 1; i <= n; i++) {
            int l = intervals[i - 1][0];
            int weight = intervals[i - 1][2];
            int origIdx = intervals[i - 1][3];

            // Find last non-overlapping interval (rightEnd < l)
            int p = binarySearch(rightEnds, i - 1, l);

            for (int r = 1; r <= 4; r++) {
                // Option 1: Don't pick the i-th interval
                State best = dp[r][i - 1];

                // Option 2: Pick the i-th interval (if valid prefix exists)
                State prev = dp[r - 1][p];
                long candidateWeight = prev.weight + weight;
                List<Integer> candidateIndices = new ArrayList<>(prev.indices);
                candidateIndices.add(origIdx);
                Collections.sort(candidateIndices); // Maintain sorted order for lexicographical check

                State candidate = new State(candidateWeight, candidateIndices);

                // Compare candidate with best option
                if (isBetter(candidate, best)) {
                    best = candidate;
                }

                dp[r][i] = best;
            }
        }

        // Find global maximum across picking 1 to 4 intervals
        State bestResult = new State(0, new ArrayList<>());
        for (int r = 1; r <= 4; r++) {
            if (isBetter(dp[r][n], bestResult)) {
                bestResult = dp[r][n];
            }
        }

        int[] result = new int[bestResult.indices.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = bestResult.indices.get(i);
        }
        return result;
    }

    private int binarySearch(int[] rightEnds, int maxIdx, int targetLeft) {
        int low = 0, high = maxIdx - 1, ans = 0;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            if (rightEnds[mid] < targetLeft) {
                ans = mid + 1; // 1-based index for dp array
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    private boolean isBetter(State a, State b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        // If weights are equal, prefer lexicographically smaller index array
        int lenA = a.indices.size();
        int lenB = b.indices.size();
        int minLen = Math.min(lenA, lenB);

        for (int i = 0; i < minLen; i++) {
            if (!a.indices.get(i).equals(b.indices.get(i))) {
                return a.indices.get(i) < b.indices.get(i);
            }
        }
        return lenA < lenB;
    }

    private static class State {
        long weight;
        List<Integer> indices;

        State(long weight, List<Integer> indices) {
            this.weight = weight;
            this.indices = indices;
        }
    }
}