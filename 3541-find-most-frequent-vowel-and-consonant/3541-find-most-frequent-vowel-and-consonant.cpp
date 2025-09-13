class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int maxi1 = 0, maxi2 = 0;
        for (auto it : s) {
            mp[it]++;
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') {
                maxi1 = max(maxi1, mp[it]);
            } 
            else {
                maxi2 = max(maxi2, mp[it]);
            }
        }
        return maxi1 + maxi2;
    }
};