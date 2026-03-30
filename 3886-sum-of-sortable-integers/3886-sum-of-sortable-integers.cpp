class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i != n / i) {
                    divs.push_back(n / i);
                }
            }
        }
        int ans = 0;
        cout<<divs.size()<<endl;
        for (int& div : divs) {
            int currMax = 0, currMin = 1e9;
            int cnt = 0;
            bool flg = true;
            int prevMax = -1;
            for (int i = 0; i < n; i++) {
                currMax = max(currMax, nums[i]);
                currMin = min(currMin, nums[i]);
                cnt++;
                if (cnt == div) {
                    flg = true;
                    if (prevMax > currMin) {
                        flg = false;
                        break;
                    }
                    int idx = i - div + 1;
                    int cnt1 = 0;
                    for (int j = idx; j < idx + div; j++) {
                        if (nums[j] > (j + 1 == idx + div ? nums[idx] : nums[j + 1])) {
                            cnt1++;
                        }
                    }
                    if (cnt1 > 1) {
                        flg = false;
                        break;
                    }
                    prevMax = currMax;
                    currMax = 0;
                    currMin = 1e9;
                    cnt = 0;
                }
            }
            if (flg) {
                ans += div;
            }
        }
        return ans;
    }
};