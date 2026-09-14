class Solution {
public:
    int pred_func(vector<int>& weights, int n, int cap) {
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
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (pred_func(weights, n, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};