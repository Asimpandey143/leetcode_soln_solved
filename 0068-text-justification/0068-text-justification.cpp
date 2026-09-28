class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> cur_words;
        int cur_len = 0;

        for (const string& word : words) {
            // Check if adding the next word exceeds maxWidth (including minimum 1 space between words)
            if (cur_words.size() + cur_len + word.length() > maxWidth) {
                // Distribute extra spaces
                for (int i = 0; i < maxWidth - cur_len; ++i) {
                    cur_words[i % (cur_words.size() - 1 ? cur_words.size() - 1 : 1)] += ' ';
                }
                string line = "";
                for (const string& w : cur_words) line += w;
                res.push_back(line);
                
                cur_words.clear();
                cur_len = 0;
            }
            cur_words.push_back(word);
            cur_len += word.length();
        }

        // Handle the last line (left-justified)
        string last_line = "";
        for (int i = 0; i < cur_words.size(); ++i) {
            last_line += cur_words[i];
            if (i != cur_words.size() - 1) last_line += ' ';
        }
        last_line += string(maxWidth - last_line.length(), ' ');
        res.push_back(last_line);

        return res;
    }
};