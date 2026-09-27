class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort to easily skip duplicates
        sort(nums.begin(), nums.end());
        
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(current);
        
        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates: if the current element is the same as the previous one,
            // and it's not the first element in this recursive level's iteration, ignore it.
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Include the element and recurse
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            
            // Backtrack: remove the element to explore other subsets
            current.pop_back();
        }
    }
};