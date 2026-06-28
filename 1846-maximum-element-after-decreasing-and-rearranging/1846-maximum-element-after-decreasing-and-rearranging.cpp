class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int maxi = 1;
        int i = 1;
        int last = 1;
        while (i < n) {
            if (i < n && arr[i] == last) {
                i++;
                continue;
            }
            maxi++;
            last = maxi;
            i++;
        }
        return maxi;
    }
};