class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = ceil(n / (double)rows);
        string ans;
        for (int i = 0; i < cols; i++) {
            for (int j = i; j < n; j += (cols + 1)) {
                ans.push_back(encodedText[j]);
            }
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};