#include <string>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string result = "";
        int minLen = n + 1;
        int onesCount = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            if (s[r] == '1') {
                onesCount++;
            }

            // Shrink window from the left to trim leading zeros
            while (onesCount == k) {
                while (s[l] == '0') {
                    l++;
                }

                int currentLen = r - l + 1;
                string currentStr = s.substr(l, currentLen);

                if (currentLen < minLen) {
                    minLen = currentLen;
                    result = currentStr;
                } else if (currentLen == minLen) {
                    result = min(result, currentStr);
                }

                // Move left pointer past s[l] (which is '1') to find next candidate
                onesCount--;
                l++;
            }
        }

        return result;
    }
};