class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_nes_paran = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                max_nes_paran = max(max_nes_paran, count);
            } else if (s[i] == ')') {
                count--;
            }
        }
        return max_nes_paran;
    }
};