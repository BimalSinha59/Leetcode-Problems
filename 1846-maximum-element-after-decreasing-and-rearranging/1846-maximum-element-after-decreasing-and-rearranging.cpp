class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int maxi = 1;
        int i = 1;
        while (i < n) {
            if (i < n && arr[i] == maxi) {
                i++;
                continue;
            }
            maxi++;
            i++;
        }
        return maxi;
    }
};