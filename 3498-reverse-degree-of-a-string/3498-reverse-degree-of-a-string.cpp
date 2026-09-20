#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int reversedAlphabetIdx = 26 - (s[i] - 'a');
            int stringIdx = i + 1;
            totalDegree += reversedAlphabetIdx * stringIdx;
        }
        
        return totalDegree;
    }
};