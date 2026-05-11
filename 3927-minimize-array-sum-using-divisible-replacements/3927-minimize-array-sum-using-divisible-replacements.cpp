class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long sum = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int& num : nums) {
            int divisor = -1;
            bool flg = true;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    if (st.count(i)) {
                        sum = sum + 1LL * i;
                        flg = false;
                        break;
                    } else if (st.count(num / i)) {
                        divisor = num / i;
                    }
                }
            }
            if (flg && divisor != -1) {
                sum = sum + 1LL * divisor;
            } else if (flg) {
                sum = sum + 1LL * num;
            }
        }
        return sum;
    }
};