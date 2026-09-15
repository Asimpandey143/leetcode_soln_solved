class Solution {
public:
    bool isMatch(string s, string p) {
        int sIdx = 0, pIdx = 0;
        int match = 0, starIdx = -1;
        int sLen = s.length(), pLen = p.length();
        
        while (sIdx < sLen) {
            // Characters match or pattern has '?'
            if (pIdx < pLen && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            } 
            // Pattern has '*'
            else if (pIdx < pLen && p[pIdx] == '*') {
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            } 
            // Last pattern character was '*', backtrack
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            } 
            // Mismatch and no star to fall back on
            else {
                return false;
            }
        }
        
        // Check for remaining trailing '*' in pattern
        while (pIdx < pLen && p[pIdx] == '*') {
            pIdx++;
        }
        
        return pIdx == pLen;
    }
};