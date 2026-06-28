class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> counts(n + 1, 0);
        for (int i = 0; i < n; i++) {
            counts[min(arr[i], n)]++;
        }
        int maxi = 1;
        for (int i = 2; i <= n; i++) {
            maxi = min(maxi + counts[i], i);
        }
        return maxi;
    }
};