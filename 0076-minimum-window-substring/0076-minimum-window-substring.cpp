#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> tFreq(128, 0);
        int required = 0;
        for (char c : t) {
            if (tFreq[c] == 0) required++;
            tFreq[c]++;
        }

        vector<int> windowFreq(128, 0);
        int formed = 0;
        
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (r < s.length()) {
            char c = s[r];
            windowFreq[c]++;

            if (tFreq[c] > 0 && windowFreq[c] == tFreq[c]) {
                formed++;
            }

            // Try to shrink the window from the left once all required characters are matched
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }

                char leftChar = s[l];
                windowFreq[leftChar]--;
                if (tFreq[leftChar] > 0 && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};