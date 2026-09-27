class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        
        // Step 1: Find matching parentheses and store their pair indices
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        string result;
        
        // Step 2: Traverse the string. Jump to the matching bracket and reverse direction.
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i]; // Teleport to the matching parenthesis
                d = -d;      // Reverse the traversal direction
            } else {
                result += s[i];
            }
        }
        
        return result;
    }
};