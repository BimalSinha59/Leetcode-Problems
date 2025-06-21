class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int os = 0, es = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                os++;
            } else {
                es++;
            }
        }
        if (abs(os - es) > 1) {
            return -1;
        }
        if (n & 1) {
            if (os > es) {
                vector<int> idx;
                for (int i = 0; i < n; i++) {
                    if (nums[i] & 1) {
                        idx.push_back(i);
                    }
                }
                int ans = 0;
                int x = 0;
                for (auto it : idx) {
                    ans += abs(it - x);
                    x += 2;
                }
                return ans;
            } else {
                vector<int> idx;
                for (int i = 0; i < n; i++) {
                    if (!(nums[i] & 1)) {
                        idx.push_back(i);
                    }
                }
                int ans = 0;
                int x = 0;
                for (auto it : idx) {
                    ans += abs(it - x);
                    x += 2;
                }
                return ans;
            }
        } else {
            int ans1 = 0;
            vector<int> idx1;
            for (int i = 0; i < n; i++) {
                if (nums[i] & 1) {
                    idx1.push_back(i);
                }
            }
            int x1 = 0;
            for (auto it : idx1) {
                ans1 += abs(it - x1);
                x1 += 2;
            }

            int ans2 = 0;
            vector<int> idx2;
            for (int i = 0; i < n; i++) {
                if (!(nums[i] & 1)) {
                    idx2.push_back(i);
                }
            }
            int x2 = 0;
            for (auto it : idx2) {
                ans2 += abs(it - x2);
                x2 += 2;
            }
            return min(ans1, ans2);
        }
    }
};