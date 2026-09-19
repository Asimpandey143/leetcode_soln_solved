#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point inside the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Calculate squared distance from circle center to closest point
        int dx = closestX - xCenter;
        int dy = closestY - yCenter;
        
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};