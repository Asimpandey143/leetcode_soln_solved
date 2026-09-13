#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect coordinates of all 1s in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        // Map to count the frequency of each translation vector (dx, dy)
        // Encode (dx, dy) into a single integer key since dx, dy in range [-30, 30]
        unordered_map<int, int> vectorCount;
        int maxOverlap = 0;

        for (auto& [r1, c1] : ones1) {
            for (auto& [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;
                
                // Encode vector (dr, dc) into a unique key
                int key = (dr + 100) * 200 + (dc + 100);
                
                vectorCount[key]++;
                maxOverlap = max(maxOverlap, vectorCount[key]);
            }
        }

        return maxOverlap;
    }
};