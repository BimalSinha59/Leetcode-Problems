class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int& num : arr1) {
            string str = to_string(num);
            for (int i = 1; i <= str.size(); i++) {
                string s = str.substr(0, i);
                int pnum = stoi(s);
                mp[pnum]++;
            }
        }
        int ans = 0;
        for (int& num : arr2) {
            string str = to_string(num);
            for (int i = str.size(); i >= 1; i--) {
                string s = str.substr(0, i);
                int pnum = stoi(s);
                if (mp.count(pnum)) {
                    ans = max(ans, (int)s.size());
                    break;
                }
            }
        }
        return ans;
    }
};