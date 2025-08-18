class Solution {
public:
    int pfunc(vector<int>& weights, int n, int cap) {
        int sum = 0;
        int days = 0;
        for (int i = 0; i < n; i++) {
            sum += weights[i];
            if (sum > cap) {
                days++;
                sum = weights[i];
            }
        }
        days++;
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (pfunc(weights, n, mid) <= days) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};