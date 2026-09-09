class Solution {
public:
    int maxArea(vector<int>& h) {
        int left = 0;
        int right = h.size() - 1;
        int max_water = 0;

        while (left < right) {
            // Calculate current width and height
            int width = right - left;
            int current_height = min(h[left], h[right]);
            
            // Calculate current area and update max_water
            int current_area = width * current_height;
            max_water = max(max_water, current_area);

            // Move the pointer pointing to the shorter line
            if (h[left] < h[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};