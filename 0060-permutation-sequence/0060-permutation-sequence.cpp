class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // Compute (n-1)! and populate the list of numbers [1, 2, ..., n]
        for (int i = 1; i < n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1; // Convert to 0-based indexing

        while (true) {
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.empty()) {
                break;
            }

            k %= fact;
            fact /= numbers.size();
        }

        return ans;
    }
};