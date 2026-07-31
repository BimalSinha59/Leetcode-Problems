class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char& ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int minPushes = 0;
        for (int i = 0; i < 8; i++) {
            minPushes += freq[i];
        }
        for (int i = 8; i < 16; i++) {
            minPushes += 2 * freq[i];
        }
        for (int i = 16; i < 24; i++) {
            minPushes += 3 * freq[i];
        }
        for (int i = 24; i < 26; i++) {
            minPushes += 4 * freq[i];
        }
        return minPushes;
    }
};