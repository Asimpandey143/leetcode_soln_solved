#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int oddCount = 0;
        char midChar = 0;
        for (int c = 0; c < 26; ++c) {
            if (freq[c] % 2 != 0) {
                oddCount++;
                midChar = 'a' + c;
            }
        }

        if (oddCount > 1) return "";

        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; ++c) {
            halfCount[c] = freq[c] / 2;
        }

        int halfLen = n / 2;

        auto buildPalindrome = [&](const string& prefix, vector<int> avail) -> string {
            string firstHalf = prefix;
            for (int c = 0; c < 26; ++c) {
                while (avail[c] > 0) {
                    firstHalf += (char)('a' + c);
                    avail[c]--;
                }
            }

            string secondHalf = firstHalf;
            reverse(secondHalf.begin(), secondHalf.end());

            if (n % 2 != 0) {
                return firstHalf + midChar + secondHalf;
            } else {
                return firstHalf + secondHalf;
            }
        };

        // Try prefix length from halfLen down to 0
        for (int len = halfLen; len >= 0; --len) {
            vector<int> req(26, 0);
            bool possible = true;
            for (int j = 0; j < len; ++j) {
                req[target[j] - 'a']++;
            }

            for (int c = 0; c < 26; ++c) {
                if (req[c] > halfCount[c]) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

            vector<int> avail(26, 0);
            for (int c = 0; c < 26; ++c) {
                avail[c] = halfCount[c] - req[c];
            }

            string prefix = target.substr(0, len);

            if (len == halfLen) {
                string candidate = buildPalindrome(prefix, avail);
                if (candidate > target) return candidate;
                continue;
            }

            int targetChar = target[len] - 'a';
            for (int c = targetChar + 1; c < 26; ++c) {
                if (avail[c] > 0) {
                    avail[c]--;
                    string candidate = buildPalindrome(prefix + (char)('a' + c), avail);
                    if (candidate > target) return candidate;
                    avail[c]++;
                }
            }
        }

        return "";
    }
};