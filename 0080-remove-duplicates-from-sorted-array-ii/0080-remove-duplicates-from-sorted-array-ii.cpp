#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        
        for (int num : nums) {
            // Allow element if we have fewer than 2 elements,
            // or if the current element isn't a duplicate of nums[k - 2]
            if (k < 2 || num != nums[k - 2]) {
                nums[k] = num;
                k++;
            }
        }
        
        return k;
    }
};