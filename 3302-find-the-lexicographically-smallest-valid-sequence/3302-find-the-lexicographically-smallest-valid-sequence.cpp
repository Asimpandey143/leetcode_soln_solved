#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] stores the maximum index in word1 from which word2[j...] can be matched as a subsequence
        vector<int> last(m + 1, -1);
        last[m] = n; // Base case

        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> res;
        bool used_change = false;
        int j = 0;

        for (int i = 0; i < n && j < m; i++) {
            bool matches = (word1[i] == word2[j]);
            
            // Check if we can match word1[i] to word2[j]
            // Case 1: Exact match
            // Case 2: Mismatch, but we can change word1[i] to word2[j] if:
            //   - We haven't used the change yet
            //   - The rest of word2[j + 1...] can fit in word1[i + 1...] (checked via last[j + 1] > i)
            if (matches || (!used_change && last[j + 1] > i)) {
                if (!matches) {
                    used_change = true;
                }
                res.push_back(i);
                j++;
            }
        }

        return (res.size() == m) ? res : vector<int>();
    }
};