class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int temp = -1;
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = (s + e) / 2;
            int missings = arr[mid] - (mid + 1);
            if (missings >= k) {
                temp = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        if (temp == -1) {
            return n + k;
        }
        return k + temp;
    }
};