class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 1e9;
        int i = 0;
        for (int& num : nums) {
            int r;
            if (mp.count(num)) {
                ans = min(ans, i - mp[num]);
            }
            for (r = 0; num > 0; num /= 10) {
                r = r * 10 + (num % 10);
            }
            mp[r] = i;
            i++;
        }
        return ans == 1e9 ? -1 : ans;
    }
};