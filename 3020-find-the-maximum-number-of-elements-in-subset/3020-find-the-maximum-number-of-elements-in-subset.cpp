class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        int ans = 1;
        for (auto& it : mp) {
            long long num = it.first;
            int len = 0;
            if (num == 1) {
                len = mp[1] & 1 ? mp[1] : mp[1] - 1;
                ans = max(ans, len);
                continue;
            }
            bool flg = false;
            while (mp.find(num) != mp.end()) {
                if (mp[num] == 1) {
                    len++;
                    flg = true;
                    break;
                } else {
                    len += 2;
                }
                num = num * num;
                if (num > 1e9) {
                    break;
                }
            }
            len += flg ? 0 : -1;
            ans = max(ans, len);
        }
        return ans;
    }
};