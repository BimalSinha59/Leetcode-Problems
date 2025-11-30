class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            string str = to_string(num);
            while (!str.empty() && str.back() == '0') {
                str.pop_back();
            }
            reverse(str.begin(), str.end());
            num = stoi(str);
            if (mp.find(num) != mp.end() && mp[num] > i) {
                ans = min(ans, mp[num] - i);
            }
        }
        if (ans == 1e9) {
            return -1;
        }
        return ans;
    }
};