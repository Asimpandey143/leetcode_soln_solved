#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        // Pruning: If frequency counts don't match, s2 cannot be a scramble of s1
        vector<int> count(26, 0);
        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0) return memo[key] = false;
        }

        // Try all split points i
        for (int i = 1; i < n; ++i) {
            // Case 1: Without Swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: With Swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};