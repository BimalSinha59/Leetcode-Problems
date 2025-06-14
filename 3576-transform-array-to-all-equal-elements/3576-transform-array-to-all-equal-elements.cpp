class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        int mc = 0, pc = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                pc++;
            } else {
                mc++;
            }
        }
        if (mc == 0 || pc == 0) {
            return true;
        } else if (mc & 1 && pc & 1) {
            return false;
        } else if (mc & 1 && !(pc & 1)) {
            int ans = 0;
            int i = 0;
            int j;
            while (i < n) {
                while (i < n && nums[i] != 1) {
                    i++;
                }
                j = i + 1;
                while (j < n && nums[j] == -1) {
                    j++;
                }
                if (i < n && j < n) {
                    ans += (j - i);
                }

                i = j + 1;
            }
            return ans <= k;
        } else if (!(mc & 1) && pc & 1) {
            int ans = 0;
            int i = 0;
            int j;
            while (i < n) {
                while (i < n && nums[i] != -1) {
                    i++;
                }
                j = i + 1;
                while (j < n && nums[j] == 1) {
                    j++;
                }
                if (i < n && j < n) {
                    ans += (j - i);
                }
                i = j + 1;
            }
            return ans <= k;
        } else {
            int ans1 = 0;
            int i = 0;
            int j;
            while (i < n) {
                while (i < n && nums[i] != 1) {
                    i++;
                }
                j = i + 1;
                while (j < n && nums[j] == -1) {
                    j++;
                }
                if (i < n && j < n) {
                    ans1 += (j - i);
                }
                i = j + 1;
            }
            int ans2 = 0;
            int l = 0;
            int m;
            while (l < n) {
                while (l < n && nums[l] != -1) {
                    l++;
                }
                m = l + 1;
                while (m < n && nums[m] == 1) {
                    m++;
                }
                if (l < n && m < n) {
                    ans2 += (m - l);
                }
                l = m + 1;
            }
            return min(ans1, ans2) <= k;
        }
        return false;
    }
};