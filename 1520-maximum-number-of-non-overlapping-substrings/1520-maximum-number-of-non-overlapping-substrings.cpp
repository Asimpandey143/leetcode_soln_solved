#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        // Step 1: Find first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }

        // Step 2: Expand valid substrings for each character's starting position
        vector<pair<int, int>> validIntervals;
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            int l = first[i];
            int r = last[i];
            bool isValid = true;
            
            for (int j = l; j <= r; ++j) {
                int ch = s[j] - 'a';
                if (first[ch] < l) {
                    // Character appears before 'l', so 'l' isn't a valid starting point
                    isValid = false;
                    break;
                }
                r = max(r, last[ch]);
            }
            
            if (isValid) {
                validIntervals.push_back({r, l}); // store end first for easy sorting
            }
        }

        // Step 3: Sort by end position and greedily pick non-overlapping intervals
        sort(validIntervals.begin(), validIntervals.end());
        
        vector<string> result;
        int lastEnd = -1;
        
        for (auto& interval : validIntervals) {
            int r = interval.first;
            int l = interval.second;
            
            if (l > lastEnd) {
                result.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }
        
        return result;
    }
};