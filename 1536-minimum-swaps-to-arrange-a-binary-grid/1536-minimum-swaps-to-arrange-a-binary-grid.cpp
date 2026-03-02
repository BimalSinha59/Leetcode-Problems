class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zs(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                cnt++;
            }
            zs[i] = cnt;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int req = n - i - 1;
            int j = i;
            while (j < n && zs[j] < req) {
                j++;
            }
            if (j == n) {
                return -1;
            }
            while (j > i) {
                swap(zs[j], zs[j - 1]);
                j--;
                ans++;
            }
        }
        return ans;
    }
};