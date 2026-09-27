class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int startIndex, vector<string>& path, vector<string>& result) {
        // Base case: if we have 4 valid parts, check if we've consumed the whole string
        if (path.size() == 4) {
            if (startIndex == s.length()) {
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        // Try extracting a part of length 1, 2, or 3
        for (int len = 1; len <= 3; ++len) {
            if (startIndex + len > s.length()) break;
            
            string part = s.substr(startIndex, len);
            
            // Invalid condition: leading zero in a multi-digit number, or value > 255
            if ((part.length() > 1 && part[0] == '0') || stoi(part) > 255) {
                continue; 
            }

            // Choose, explore, then backtrack
            path.push_back(part);
            backtrack(s, startIndex + len, path, result);
            path.pop_back();
        }
    }
};