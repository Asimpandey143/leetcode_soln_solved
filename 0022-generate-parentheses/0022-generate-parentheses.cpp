#include <vector>
#include <string>

class Solution {
public:
    void backtrack(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        // Base case: if current string length reaches 2 * n
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // If we can still add an opening parenthesis
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        
        // If we can add a closing parenthesis (only when close < open to remain valid)
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};